#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include "dist.h"
#include "funs.h"
#include <math.h>
#define ERROR(S) fprintf(stderr, (S)), exit(1)
#define USAGE_ERROR() fprintf(stderr, "Usage: %s [-lir] [-z z_val | -t t_val [mu1 mu2]]\n", argv[0]), exit(1);

/* globals */
double (*fun)(double[]);
double nums[MAX_ARGS];

void setfun(char distflag, bool inverse, bool left, bool right);

void setfun(char distflag, bool inverse, bool left, bool right)
{
    Dist dist;
    if(distflag == 'z')
        dist = zdist;
    else
        dist = tdist;
    fun = zdist.funs[inverse];
}

int main(int argc, char *argv[])
{
    double nums[MAX_ARGS];
    int i = 0;
    char opt, distflag = 0;
    bool left, right, inverse;
    const char* dists = "zt";

    left = right = inverse = false;

    while ((opt = getopt(argc, argv, "z:t:lri")) != -1) {

        if(strchr(dists, opt)) {
            if(distflag != 0)
                ERROR("Error: Can only use one distribution at a time\n");
            else {
                distflag = opt;
                if(optarg == NULL)
                    exit(1);
                nums[i++] = atof(optarg);
            }
        }
        else
            switch(opt) {
                case 'i':
                    inverse = true;
                    break;
                case 'r':
                    right = true;
                    break;
                case 'l':
                    left = true;
                    break;
                default:
                    USAGE_ERROR();
                    break;
            }
    }

    if(distflag == 0)
        USAGE_ERROR();

    setfun(distflag, inverse, left, right);

    double result = fun(nums);
    printf("%g\n", result);

    return 0;
}
