#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include "funs.h"
#include "dist.h"
#include <math.h>
#define CONTENIOUS "zt"
#define DISCRETE ""
#define DISTRIBUTION CONTENIOUS DISCRETE
#define OPTIONS "ilr"
#define ERROR(...) fprintf(stderr, __VA_ARGS__), exit(1)
#define ERROR_USAGE() ERROR("Usage: %s [-lir] [-z | -t] n1 [n2] [n3] [n4]\n", argv[0])
#define DEFAULT_DIST 'z'

/* globals */
double (*fun)(double[]);
double nums[MAX_ARGS];

void setfun(char distflag, bool inverse, bool left, bool right);
int collect_args(int argc, char* argv[]);
void collect_opts(int argc, char* argv[], char* distflag, bool *inverse, bool *left, bool *right);


void setfun(char distflag, bool inverse, bool left, bool right)
{
    Contenious dist;
    if(distflag == 'z')
        dist = zdist;
    else
        dist = tdist;
    if(inverse)
        fun = dist.invcdfs.left;
    else
        fun = dist.cdfs.left;
}


/* Assign arguements into nums and return how many of them are there */
int collect_args(int argc, char* argv[])
{
    int n = 0;
    char *signal; /* rest of the string */

    for(int i = optind; i < argc; i++, n++) {
        nums[n] = strtod(argv[i], &signal);
        if(*signal != 0) /* string isn't entirely a number */
            ERROR("Error: %s cannot be interpreted as a number\n", argv[i]);
    }

    return n;
}

void collect_opts(int argc, char* argv[], char* distflag, bool *inverse, bool *left, bool *right)
{
    char opt;
    while((opt = getopt(argc, argv, "ztlri")) != -1) {
        if(strchr(CONTENIOUS, opt)) {
            if(*distflag != 0)
                ERROR("Error: Multiple distributions given. Aborting...\n");
            else
                *distflag = opt;
        }
        else switch(opt) {
            case 'i':
                *inverse = true;
                break;
            case 'r':
                *right = true;
                break;
            case 'l':
                *left = true;
                break;
            default:
                ERROR_USAGE();
                break;
        }
    }
}

int main(int argc, char *argv[])
{
    char distflag = 0;
    bool left, right, inverse;
    left = right = inverse = false;

    collect_opts(argc, argv, &distflag, &inverse, &left, &right);

    if(optind >= argc) {
        fprintf(stderr, "Error: Missing positional arguements\n");
        ERROR_USAGE();
    }
    else if((argc - optind) > MAX_ARGS)
        ERROR("Error: Too many positional arguements\n");

    int n = collect_args(argc, argv);

    if(distflag == 0)
        distflag = DEFAULT_DIST;

    setfun(distflag, inverse, left, right);

    double result = fun(nums);
    printf("%g\n", result);

    return 0;
}
