#ifndef DIST_H
#define DIST_H

typedef struct {
    char name;
    double (*funs[])(double[]);
} Dist;

extern Dist zdist;
extern Dist tdist;

#endif
