/* main.c */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libgen.h>
#include <errno.h>
#include <string.h>
#include <getopt.h>
#include <sys/types.h>

#define OPTSTR "vi:o:f:h"
#define USAGE_FMT  "%s [-v] [-f hexflag] [-i inputfile] [-o outputfile] [-h]"
#define ERR_FOPEN_INPUT  "fopen(input, r)"
#define ERR_FOPEN_OUTPUT "fopen(output, w)"
#define ERR_DO_THE_NEEDFUL "do_the_needful blew up"
#define DEFAULT_PROGNAME "george"

int main(int argc, char* argv[]) {
    int opt;
    options_t options = { 0, 0x0, stdin, stdout };

    opterr = 0;

    while ((opt = getopt(argc, argv, OPTSTR)) != EOF)
        switch (opt) {
        case 'i':
            if (!(options.input = fopen(optarg, "r"))) {
                perror(ERR_FOPEN_INPUT);
                exit(EXIT_FAILURE);
                /* NOTREACHED */
            }
            break;

        case 'o':
            if (!(options.output = fopen(optarg, "w"))) {
                perror(ERR_FOPEN_OUTPUT);
                exit(EXIT_FAILURE);
                /* NOTREACHED */
            }
            break;

        case 'f':
            options.flags = (uint32_t)strtoul(optarg, NULL, 16);
            break;

        case 'v':
            options.verbose += 1;
            break;

        case 'h':
        default:
            usage(basename(argv[0]), opt);
            /* NOTREACHED */
            break;
        }

    if (do_the_needful(&options) != EXIT_SUCCESS) {
        perror(ERR_DO_THE_NEEDFUL);
        exit(EXIT_FAILURE);
        /* NOTREACHED */
    }

    return EXIT_SUCCESS;
}