#ifndef DIST_H
#define DIST_H

/* probability function */
typedef double (*Prob)(double[]);

typedef struct {
    Prob left;
    Prob right;
} Cdfs;

typedef struct {
    Cdfs cdfs;
    Cdfs invcdfs;
} Contenious;

typedef struct {
    Cdfs cdfs;
    Prob pdf;
} Discrete;

enum disttype { DISCRETE, CONTENIOUS };

typedef struct {
    union {
        Contenious cont;
        Discrete disc;
    };
    enum disttype type;
} Distribution;

extern Contenious zdist;
extern Contenious tdist;

#endif
