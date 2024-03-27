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

    Delimiter does not have to be a single character.
