#ifndef FUNS_H
#define FUNS_H
#define MAX_ARGS 4

double z_cdf_P(double args[]);
double z_cdf_Q(double args[]);
double z_invcdf_P(double args[]);
double z_invcdf_Q(double args[]);

double t_cdf_P(double args[]);
double t_cdf_Q(double args[]);
double t_invcdf_P(double args[]);
double t_invcdf_Q(double args[]);

double f_cdf_P(double args[]);
double f_cdf_Q(double args[]);
double f_invcdf_P(double args[]);
double f_invcdf_Q(double args[]);

double expo_pdf(double args[]);
double expo_cdf_P(double args[]);
double expo_cdf_Q(double args[]);
double expo_invcdf_P(double args[]);
double expo_invcdf_Q(double args[]);

double weibull_cdf_P(double args[]);
double weibull_cdf_Q(double args[]);
double weibull_invcdf_P(double args[]);
double weibull_invcdf_Q(double args[]);

double binomial_pdf(double args[]);
double binomial_P(double args[]);
double binomial_Q(double args[]);

double poisson_pdf(double args[]);
double poisson_P(double args[]);
double poisson_Q(double args[]);

double geo_pdf(double args[]);
double geo_P(double args[]);
double geo_Q(double args[]);

double hyper_pdf(double args[]);
double hyper_Q(double args[]);
double hyper_P(double args[]);
#endif
