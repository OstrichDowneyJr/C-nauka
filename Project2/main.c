#include <stdio.h>
#include <string.h>
#include <dirent.h>

int listFiles(const char* rootDir);

#define BUFF_MAX 100

int main(const int argc, char *argv[]) {
    char path[BUFF_MAX];
    if (argc >= 2) {
        strncpy(path, argv[1], BUFF_MAX - 1);
        path[BUFF_MAX - 1] = '\0';  // Ensure null termination
    } else if (fgets(path, BUFF_MAX, stdin) != NULL) {
        path[strcspn(path, "\n")] = 0;
    } else {
        printf("No path provided\n");
        return 1;
    }

    listFiles(path);

    return 0;
}

int listFiles(const char* rootDir) { // NOLINT(*-no-recursion)
    struct dirent *dp;
    DIR *dir = opendir(rootDir);
    
    if (!dir) {
        return 1;
    }

    while ((dp = readdir(dir)) != NULL) {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0) {
            printf("%s\n", dp->d_name);
            
            char newPath[BUFF_MAX];
            strncpy(newPath, rootDir, BUFF_MAX - 1);
            strncat(newPath, "/", BUFF_MAX - strlen(newPath) - 1);
            strncat(newPath, dp->d_name, BUFF_MAX - strlen(newPath) - 1);
            
            listFiles(newPath);
        }
    }

    closedir(dir);
    return 0;
}