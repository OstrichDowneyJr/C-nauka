#pragma warning(disable : 4994)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS
#define __STDC_WANT_LIB_EXT0__ 1
#define _GNU_SOURCE 
#define BUFF_SIZE 1023
#define DELIMITER_SIZE 3


int split_file(char* path_to_txt, char* delimters);

int main(int argc, char** argv) {

	printf("Testing function\n");
	int a = split_file("Dummy.txt", ":");
	int b = split_file("Dummy2.txt",";");
	int c = split_file("Dummy3.txt",".");

	printf("Test a:%d \t Test b:%d\t Test c:%d\n", a, b, c);
	printf("Test is successful if x=0");
	return EXIT_SUCCESS;
}


int split_file(char* path_to_txt, char* delimiters) {


	FILE* file;
	char read_buff[BUFF_SIZE];
	char* current_section;


	if ((file = fopen(path_to_txt, "r")) == NULL) {
		printf("File opening error!\n");
		printf("Tried to open %s\n",path_to_txt);
		return EXIT_FAILURE;
	}

	fgets(read_buff, BUFF_SIZE,file);
	fclose(file);
	printf("Raw version of the text file is:\n");
	printf("%s\n", read_buff);
	printf("Edited version of the text file is:\n");


	current_section= strtok(read_buff,delimiters);
	while (current_section != NULL) {
		printf("%s\n", current_section);
		current_section = strtok(NULL,delimiters); 
	}

	return EXIT_SUCCESS;

}

    