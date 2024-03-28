#include "main.h"


int main(int argc, char *argv[2]) {

	/*variables declaraion*/
	FILE* file;
	char read_buff[BUFF_SIZE];
	char delimiter[DELIMITER_SIZE];

	/*handling main arguments*/
	if (argc != 2) {
		printf("Wrong number of arguments, expected 2\n");
		return EXIT_FAILURE;
	}

	/*removing "" from delimiter's string*/
	delimiter[0] ="";
	delimiter[sizeof(delimiter-1)] ="";

	/*getting file to program's memory*/
	file = fopen(argv[0], "r");
	if (file == NULL) {
		printf("File opening error!\n");
		return EXIT_FAILURE;
	}
	fgets(read_buff, BUFF_SIZE, file);
	fclose(file);

	/*spliting strings to separate lines*/
	char* token = strtok(read_buff, delimiter);
	while (token != NULL) {
		printf("%s\n", token);
		token = strtok(NULL, delimiter);
	}

	return EXIT_SUCCESS;

}