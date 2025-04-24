/**
 * C program to list contents of a directory recursively.
 */

#include <stdio.h>
#include <string.h>
#include <dirent.h>

void listFiles(char *path);


int main(int argc, char *argv[]){
    char path[100];
    printf("Enter path to list files: ");
    scanf("%s", path);

    listFiles(path);

    return 0;
}


void listFiles(char *basePath)
{
    char path[1000];
    struct dirent *dp;
    DIR *dir = opendir(basePath);

    if (!dir) {
        return;
    }

    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
            printf("%s\n", dp->d_name);

            // Construct new path from our base path
            strcpy(path, basePath);
            strcat(path, "/");
            strcat(path, dp->d_name);

            listFiles(path);
        }
    }

    closedir(dir);
}