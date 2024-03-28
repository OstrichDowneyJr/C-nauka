#include "main.h"


int main(int argc, char *argv[2]) {

	/*handling main arguments*/
	if (argc != 2) {
		printf("Wrong number of arguments, expected 2\n");
		return EXIT_FAILURE;
	}

	/*variables declaraion*/
	FILE* file;
	char read_buff[BUFF_SIZE];


	/*getting file to programs memory*/
	file = fopen(argv[0], "r");
	if (file == NULL) {
		printf("File opening error!\n");
		return EXIT_FAILURE;
	}


	return EXIT_SUCCESS;

}