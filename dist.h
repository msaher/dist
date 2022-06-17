#ifndef DIST_H
#define DIST_H

/* probability function */
typedef double (*Prob)(double[]);

typedef struct {
    Prob left;
    Prob right;
} Cdfs;

typedef struct {
    char name;
    Cdfs cdfs;
    Cdfs invcdfs;
} Contenious;

typedef struct {
    char name;
    Cdfs cdfs;
    Prob pdf;
} Discrete;

extern Contenious zdist;
extern Contenious tdist;

#endif
