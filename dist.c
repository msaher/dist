#include "funs.h"
#include "dist.h"

Dist zdist = { .name = 'z', .funs = {z_cdf, z_invcdf} };
Dist tdist = { .name = 't', .funs = {t_cdf, t_invcdf} };
