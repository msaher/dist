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

/* double  exponential_cdf(double     args[]); */

/* double  f_cdf(double               args[]); */
/* double  f_cdfinv(double            args[]); */

/* double  weibull_cdf(double         args[]); */

double poisson_pdf(double args[]);
double poisson_p(double args[]);
double poisson_q(double args[]);

double binomial_pdf(double args[]);
double binomial_P(double args[]);
double binomial_Q(double args[]);
/* double  geometric_pdf(double       args[]); */

double hypergeometric_pdf(double args[]);
double hypergeometric_Q(double args[]);
double hypergeometric_P(double args[]);

/* double z_cdf(double z); */
/* double z_invcdf(double z); */
/* double (*t_cdf)(double, double); */
/* double (*t_invcdf)(double, double); */
/* double (*exponential_cdf)(double x, double mu); */
/* double (*f_cdf)(double x, double nu1, double nu2); */
/* double (*f_cdfinv)(double x, double nu1, double nu2); */
/* double(*weibull_cdf)(double x, double a, double b); */
/* double (*poisson_pdf)(unsigned int k, double mu); */
/* double (*poisson_cdf)(unsigned int k, double mu); */
/* double (*bionomial_pdf)(unsigned int k, double p, unsigned int n); */
/* double (*geometric_pdf)(unsigned int k, double p); */
/* double (*hypergeometric_pdf)(unsigned int k, unsigned int n1, unsigned int
 * n2, unsigned int t); */

#endif
