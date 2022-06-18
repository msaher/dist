#include "funs.h"
#include "dist.h"

Contenious zdist = {
    { z_cdf_P, z_cdf_Q },
    { z_invcdf_P, z_invcdf_Q },
};

Contenious tdist = {
    { t_cdf_P, t_cdf_Q },
    { t_invcdf_P, t_invcdf_Q },
};
