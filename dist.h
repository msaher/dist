#ifndef DIST_H
#define DIST_H
#include <stdlib.h>

/* probability function */
typedef double (*Prob)(double[]);

typedef struct {
    Prob left;
    Prob right;
} Cdfs;

typedef struct {
    Cdfs cdfs;
    Cdfs invcdfs;
    int nargs;
} Contenious;

typedef struct {
    Prob pdf;
    Cdfs cdfs;
    int nargs;
} Discrete;

enum disttype { DISCRETE, CONTENIOUS };

typedef struct {
    union {
        Contenious* cont;
        Discrete* disc;
    };
    enum disttype type;
} Distribution;

typedef struct {
    char* key;
    void* data;
} Map;

extern const Distribution defaultdist;
extern const Map contarr[];

/* void* dist_lookup(char *key, enum disttype type); */
int dist_lookup(char *key, Distribution** distptr);

#endif
