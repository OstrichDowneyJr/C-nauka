#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int ListDirectoryContents(const char* sDir){

    WIN32_FIND_DATA fdFile;
    HANDLE hFind = NULL;

    char sPath[2048];

    sprintf(sPath, "%s\\*.txt", sDir);
    if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE){
        printf("Path not found: [%s]\n", sDir);
        return 1;
    }
    do{
        if(strcmp(fdFile.cFileName, ".") != 0 && strcmp(fdFile.cFileName, "..") != 0){
            sprintf(sPath, "%s\\%s", sDir, fdFile.cFileName);

            if (fdFile.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY){
                printf("Directory: %s\n", sPath);
                ListDirectoryContents(sPath);
            }
            else {
                printf("File: %s\n", sPath);
            }
        }
    }
    while (FindNextFile(hFind, &fdFile)); 
    FindClose(hFind); 
    return 0;
}

void traverse(char* path) {

	FILE* file; 
    char buffer;

	file = fopen(path, "r");
    buffer = fgetc(file);

    while (buffer != EOF)
    {
        printf("%c", buffer);
        buffer = fgetc(file);
    }
    fclose(file);

}


int main(int argc, char** argv) {

	return 0;
}