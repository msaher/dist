#include "funsetter.h"
#include "dist.h"
#include "utils.h"
#include <stdbool.h>
#include <stdio.h>

Prob get_cont_fun(Contenious *cont, bool inverse, bool left, bool right);
Prob get_disc_fun(Discrete *disc, bool inverse, bool left, bool right);
double impossible(double args[]);

double impossible(double args[]);

Prob get_fun(Distribution *dist, bool inverse, bool left, bool right) {
  switch (dist->type) {
  case CONTENIOUS:
    return get_cont_fun(dist->cont, inverse, left, right);
  case DISCRETE:
    return get_disc_fun(dist->disc, inverse, left, right);
  default:
    return impossible; /* fall back to impossible */
    break;
  }
}

Prob get_cont_fun(Contenious *cont, bool inverse, bool left, bool right) {
  Prob fun;
  Cdfs cdfs;
  cdfs = inverse ? cont->invcdfs : cont->cdfs;
  if (left == right)
    fun = impossible;
  else
    fun = left ? cdfs.left : cdfs.right;
  return fun;
}

Prob get_disc_fun(Discrete *disc, bool inverse, bool left, bool right) {
  Prob fun;
  if (inverse)
    ERROR("Can't find the inverse of discrete distribution\n");
  if (left == right)
    fun = disc->pdf;
  else
    fun = left ? disc->cdfs.left : disc->cdfs.right;
  return fun;
}

double impossible(double args[]) { return 0; }
