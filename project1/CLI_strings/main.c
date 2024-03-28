#include "main.h"


int main(int argc, char *argv[]) {

	///*handling main arguments*/
	if (argc != 3) {
		printf("Wrong number of arguments, expected 2\n");
		return EXIT_FAILURE;
	}
	FILE* file;
	/*variables declaraion*/
	char read_buff[BUFF_SIZE];

	/*getting file to program's memory*/
	if ((file = fopen(argv[1], "r")) == NULL) {
		printf("File opening error!\n");
		return EXIT_FAILURE;
	}
	fgets(read_buff, BUFF_SIZE,file);
	fclose(file);
	/*spliting strings to separate lines*/
	char* token;
	/*to nie dziala, nie umiem zapisac tego wskaznika*/
	token= strtok(read_buff,*argv[2]);
	while (token != NULL) {
		printf("%s\n", token);
		token = strtok(NULL,*argv[2]); /*tu tez*/
	}


	return EXIT_SUCCESS;

}

    