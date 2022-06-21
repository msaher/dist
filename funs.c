#include <gsl/gsl_cdf.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_rng.h>

double z_cdf_P(double args[]) { return gsl_cdf_gaussian_P(args[0], 1); }
double z_cdf_Q(double args[]) { return gsl_cdf_gaussian_Q(args[0], 1); }
double z_invcdf_P(double args[]) { return gsl_cdf_gaussian_Pinv(args[0], 1); }
double z_invcdf_Q(double args[]) { return gsl_cdf_gaussian_Qinv(args[0], 1); }

double t_cdf_P(double args[]) { return gsl_cdf_tdist_P(args[0], args[1]); }
double t_cdf_Q(double args[]) { return gsl_cdf_tdist_Q(args[0], args[1]); }
double t_invcdf_P(double args[]) { return gsl_cdf_tdist_Pinv(args[0], args[1]); }
double t_invcdf_Q(double args[]) { return gsl_cdf_tdist_Qinv(args[0], args[1]); }

double f_cdf_P(double args[]) { return gsl_cdf_fdist_P(args[0], args[1], args[2]); }
double f_cdf_Q(double args[]) { return gsl_cdf_fdist_Q(args[0], args[1], args[2]); }
double f_invcdf_P(double args[]) { return gsl_cdf_fdist_Pinv(args[0], args[1], args[2]); }
double f_invcdf_Q(double args[]) { return gsl_cdf_fdist_Qinv(args[0], args[1], args[2]); }

double expo_pdf(double args[]) { return gsl_ran_exponential_pdf(args[0], args[1]); }
double expo_cdf_P(double args[]) { return gsl_cdf_exponential_P(args[0], args[1]); }
double expo_cdf_Q(double args[]) { return gsl_cdf_exponential_Q(args[0], args[1]); }
double expo_invcdf_P(double args[]) { return gsl_cdf_exponential_Pinv(args[0], args[1]); }
double expo_invcdf_Q(double args[]) { return gsl_cdf_exponential_Qinv(args[0], args[1]); }

double weibull_cdf_P(double args[]) { return gsl_cdf_weibull_P(args[0], args[1], args[2]); }
double weibull_cdf_Q(double args[]) { return gsl_cdf_weibull_Q(args[0], args[1], args[2]); }
double weibull_invcdf_P(double args[]) { return gsl_cdf_weibull_Pinv(args[0], args[1], args[2]); }
double weibull_invcdf_Q(double args[]) { return gsl_cdf_weibull_Qinv(args[0], args[1], args[2]); }

double binomial_pdf(double args[]) { return gsl_ran_binomial_pdf(args[0], args[1], args[2]); }
double binomial_P(double args[]) { return gsl_cdf_binomial_P(args[0], args[1], args[2]); }
double binomial_Q(double args[]) { return gsl_cdf_binomial_Q(args[0], args[1], args[2]); }

double poisson_pdf(double args[]) { return gsl_ran_poisson_pdf(args[0], args[1]); }
double poisson_P(double args[]) { return gsl_cdf_poisson_P(args[0], args[1]); }
double poisson_Q(double args[]) { return gsl_cdf_poisson_Q(args[0], args[1]); }

double geo_pdf(double args[]) { return gsl_ran_geometric_pdf(args[0], args[1]); }
double geo_P(double args[]) { return gsl_cdf_geometric_P(args[0], args[1]); }
double geo_Q(double args[]) { return gsl_cdf_geometric_Q(args[0], args[1]); }

double hyper_pdf(double args[]) { return gsl_ran_hypergeometric_pdf(args[0], args[1], args[2], args[3]); }
double hyper_Q(double args[]) { return gsl_cdf_hypergeometric_Q(args[0], args[1], args[2], args[3]); }
double hyper_P(double args[]) { return gsl_cdf_hypergeometric_P(args[0], args[1], args[2], args[3]); }
