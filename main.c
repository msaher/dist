#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include "funs.h"
#include "dist.h"
#include <math.h>
#include "utils.h"
#include "funsetter.h"

int collect_args(double nums[], int argc, char* argv[]);
bool collect_opts(Distribution** dist, int argc, char* argv[], bool *inverse, bool *left, bool *right);

/* Assign arguements into nums and return how many of them are there */
int collect_args(double nums[], int argc, char* argv[])
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

bool collect_opts(Distribution** dist, int argc, char* argv[], bool *inverse, bool *left, bool *right)
{
    char opt;
    char optstr[2]; /* string version of opt. Used for look up */
    optstr[1] = '\0';
    bool distflag = false; /* used to indicate that a dist has been found */
    while((opt = getopt(argc, argv, "ztlrib")) != -1) {
        switch(opt) {
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
                optstr[0] = opt;
                if(dist_lookup(optstr, dist))
                    if(distflag)
                        ERROR("Error: Multiple Distributions given\n");
                    else
                        distflag = true;
                else
                    ERROR_USAGE();
                break;
        }
    }
        return distflag;
}

int main(int argc, char *argv[])
{

    Distribution* dist = malloc(sizeof(Distribution));
    bool left, right, inverse; /* flags */
    left = right = inverse = false;

    /* use default distribution if no distflag has been set */
    if(!collect_opts(&dist, argc, argv, &inverse, &left, &right)) {
        *dist =  defaultdist;
    }

    enum disttype type = dist->type;

    /* set sane defaults if direction is unspecified */
    if(left == right && left == false) /* direction not set expliclty */
        switch(type) {
            case CONTENIOUS:
                left = true;
                break;
            case DISCRETE:
                left = right = true;
                break;
        }

    /* positional arguements */
    double nums[MAX_ARGS];
    int req = (type == CONTENIOUS) ? dist->cont->nargs : dist->disc->nargs;
    int n = collect_args(nums, argc, argv);
    if(req != n)
        ERROR("Invalid number of arguements exepcted %d, but got %d\n", req, n);

    /* extract probability function from distribution */
    Prob fun = get_fun(dist, inverse, left, right);

    double result = fun(nums);
    printf("%g\n", result);
    free(dist);

    return 0;
}
