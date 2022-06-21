#include <gsl/gsl_cdf.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

double  z_cdf_P(double               args[])  {  return  gsl_cdf_gaussian_P(args[0],          1);        }
double  z_cdf_Q(double               args[])  {  return  gsl_cdf_gaussian_Q(args[0],          1);        }
double  z_invcdf_P(double            args[])  {  return  gsl_cdf_gaussian_Pinv(args[0],       1);        }
double  z_invcdf_Q(double            args[])  {  return  gsl_cdf_gaussian_Qinv(args[0],       1);        }

double  t_cdf_P(double               args[])  {  return  gsl_cdf_tdist_P(args[0],             args[1]);  }
double  t_cdf_Q(double               args[])  {  return  gsl_cdf_tdist_Q(args[0],             args[1]);  }
double  t_invcdf_P(double            args[])  {  return  gsl_cdf_tdist_Pinv(args[0],          args[1]);  }
double  t_invcdf_Q(double            args[])  {  return  gsl_cdf_tdist_Qinv(args[0],          args[1]);  }

/* double  exponential_cdf(double     args[])  {  return  gsl_cdf_exponential_P(args[0],       args[1]);  } */                     
/* double  f_cdf(double               args[])  {  return  gsl_cdf_fdist_Q(args[0],             args[1],   args[2]);  } */          
/* double  f_cdfinv(double            args[])  {  return  gsl_cdf_fdist_Qinv(args[0],          args[1],   args[2]);  } */          
/* double  weibull_cdf(double         args[])  {  return  gsl_cdf_weibull_P(args[0],           args[1],   args[2]);  } */          
/* double  poisson_pdf(double         args[])  {  return  gsl_ran_poisson_pdf(args[0],         args[1]);  } */                     
/* double  poisson_cdf(double         args[])  {  return  gsl_cdf_poisson_P(args[0],           args[1]);  } */                     
double bionomial_pdf(double       args[])  {  return  gsl_ran_binomial_pdf(args[0],        args[1],   args[2]);  }          
double binomial_P(double args[]) { return gsl_cdf_binomial_P(args[0], args[1], args[2]);}
double binomial_Q(double args[]) { return gsl_cdf_binomial_Q(args[0], args[1], args[2]);}

/* double  geometric_pdf(double       args[])  {  return  gsl_ran_geometric_pdf(args[0],       args[1]);  } */                     
/* double  hypergeometric_pdf(double  args[])  {  return  gsl_ran_hypergeometric_pdf(args[0],  args[1],   args[2],   args[3]);  } */
