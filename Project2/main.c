#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <handleapi.h>
#include <minwinbase.h>
#include <fileapi.h>
#include <errhandlingapi.h>

int ListDirectoryContents(const char* sDir){

    WIN32_FIND_DATA FindFileData;
	HANDLE hFind;
	char DirSpec[MAX_PATH];
	snprintf(DirSpec, MAX_PATH,"%s\\*", sDir);
	
	if (snprintf(DirSpec, MAX_PATH, "%s\\*", sDir) >= MAX_PATH) {
		printf("Directory path is too long.\n");
		return 1;
	}

	hFind =  FindFirstFileA(DirSpec, &FindFileData);
	if (hFind == INVALID_HANDLE_VALUE) {
		printf ("FindFirstFile failed (%d)\n", GetLastError());
		return 1;
	} 

	do {
		if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			wprintf(TEXT("  %s   <DIR>\n"), FindFileData.cFileName);
		else
			wprintf(TEXT("  %s \n"), FindFileData.cFileName);
	} while (FindNextFile(hFind, &FindFileData) != 0);

	FindClose(hFind);
    return 0;
}


int main(int argc, char* argv[]) {
    if (argc < 2) {
		printf("Usage: %s <directory>\n", argv[0]);
		return 1;
	}

    ListDirectoryContents(argv[1]);
	return 0;
}