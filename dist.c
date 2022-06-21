#include "funs.h"
#include "dist.h"
#include <stdlib.h>
#include <string.h>

static Contenious zdist = {
    { z_cdf_P, z_cdf_Q },
    { z_invcdf_P, z_invcdf_Q },
    1
};

static Contenious tdist = {
    { t_cdf_P, t_cdf_Q },
    { t_invcdf_P, t_invcdf_Q },
    2,
};

static Discrete binomial = {
    binomial_pdf,
    { binomial_P, binomial_Q },
    3,
};

static Discrete poisson = {
    poisson_pdf,
    { poisson_p, poisson_q },
    3,
};

const Map contarr[] = { 
    { "t", &tdist },
    { "z", &zdist },
};

const Map distarr[] = {
    { "b", &binomial},
    { "p", &poisson}
};


const Distribution defaultdist = { .cont = &zdist, .type = CONTENIOUS };

int mapcmp(Map* a, Map* b)
{
    return strcmp(a->key, b->key);
}

void* dist_lookup_internal(char *key, enum disttype type)
{
    Map map = {key , NULL};
    Map* result;
    const Map* arr = (type == CONTENIOUS) ? contarr : distarr;

    result = bsearch(&map, arr, sizeof(contarr)/sizeof(Map), sizeof(Map), (int (*)(const void*, const void*)) mapcmp);

    if(result == NULL)
        return NULL;

    return result->data;
}

int dist_lookup(char *key, Distribution** distptr)
{
    if(((*distptr)->cont = dist_lookup_internal(key, CONTENIOUS)) != NULL)
        (*distptr)->type = CONTENIOUS;

    else if(((*distptr)->disc = dist_lookup_internal(key, DISCRETE)) != NULL)
        (*distptr)->type = DISCRETE;
    else
        return 0;

    return 1;
}
