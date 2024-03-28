Write a CLI tool that takes the path to a text file (.txt) as a first argument and
a single character representing delimiter as the second argument. Using the tool should look as follows:

project1 <path_to_a_file>.txt ":"

The tool should read the text file to the memory, split it according to the delimiter,
and print each part of the split as a new line to the console. e.g.

test.txt
a:b:c:def:g

project1 test.txt ":"

output:
a
b
c
def
g

Notes:

 - Delimiter does not have to be a single character.


/* main.c */

/* 0 copyright/licensing */
/* 1 includes */
/* 2 defines */
/* 3 external declarations */
/* 4 typedefs */
/* 5 global variable declarations */
/* 6 function prototypes */

int main(int argc, char *argv[]) {
/* 7 command-line parsing */
}

/* 8 function declarations */
