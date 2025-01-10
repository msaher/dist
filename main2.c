#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <gsl/gsl_cdf.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_rng.h>

#define USAGE "Usage: %s [-lir] [-e | -f | -t | -w | -z | -b | -g | -p | -y | -h] args\n"
#define OPTIONS "lrih"
#define DISTRIBUTIONS "eftwzbgpy"
#define IS_CONTENTIOUS(dist) (dist <= WEIBULL)

#define CALL_DISCRETE(cfg, nums, pdf, cdf_p, cdf_q) \
    ((cfg.left == cfg.right) ? pdf(nums) : \
    ((cfg.left) ? cdf_p : cdf_q)(nums))

#define CALL_CONTINUOUS(cfg, nums, cdf_p, cdf_q, invcdf_p, invcdf_q) \
    ((cfg.left == cfg.right) ? 0.0 : \
     ((cfg.inverse) ? \
        ((cfg.left) ? invcdf_p : invcdf_q)(nums) : \
        ((cfg.left) ? cdf_p : cdf_q)(nums)))

double z_cdf_P(double args[])          { return gsl_cdf_gaussian_P(args[0], 1); }
double z_cdf_Q(double args[])          { return gsl_cdf_gaussian_Q(args[0], 1); }
double z_invcdf_P(double args[])       { return gsl_cdf_gaussian_Pinv(args[0], 1); }
double z_invcdf_Q(double args[])       { return gsl_cdf_gaussian_Qinv(args[0], 1); }

double t_cdf_P(double args[])          { return gsl_cdf_tdist_P(args[0], args[1]); }
double t_cdf_Q(double args[])          { return gsl_cdf_tdist_Q(args[0], args[1]); }
double t_invcdf_P(double args[])       { return gsl_cdf_tdist_Pinv(args[0], args[1]); }
double t_invcdf_Q(double args[])       { return gsl_cdf_tdist_Qinv(args[0], args[1]); }

double f_cdf_P(double args[])          { return gsl_cdf_fdist_P(args[0], args[1], args[2]); }
double f_cdf_Q(double args[])          { return gsl_cdf_fdist_Q(args[0], args[1], args[2]); }
double f_invcdf_P(double args[])       { return gsl_cdf_fdist_Pinv(args[0], args[1], args[2]); }
double f_invcdf_Q(double args[])       { return gsl_cdf_fdist_Qinv(args[0], args[1], args[2]); }

double expo_pdf(double args[])         { return gsl_ran_exponential_pdf(args[0], args[1]); }
double expo_cdf_P(double args[])       { return gsl_cdf_exponential_P(args[0], args[1]); }
double expo_cdf_Q(double args[])       { return gsl_cdf_exponential_Q(args[0], args[1]); }
double expo_invcdf_P(double args[])    { return gsl_cdf_exponential_Pinv(args[0], args[1]); }
double expo_invcdf_Q(double args[])    { return gsl_cdf_exponential_Qinv(args[0], args[1]); }

double weibull_cdf_P(double args[])    { return gsl_cdf_weibull_P(args[0], args[1], args[2]); }
double weibull_cdf_Q(double args[])    { return gsl_cdf_weibull_Q(args[0], args[1], args[2]); }
double weibull_invcdf_P(double args[]) { return gsl_cdf_weibull_Pinv(args[0], args[1], args[2]); }
double weibull_invcdf_Q(double args[]) { return gsl_cdf_weibull_Qinv(args[0], args[1], args[2]); }

double binomial_pdf(double args[])     { return gsl_ran_binomial_pdf(args[0], args[1], args[2]); }
double binomial_P(double args[])       { return gsl_cdf_binomial_P(args[0], args[1], args[2]); }
double binomial_Q(double args[])       { return gsl_cdf_binomial_Q(args[0], args[1], args[2]); }

double poisson_pdf(double args[])      { return gsl_ran_poisson_pdf(args[0], args[1]); }
double poisson_P(double args[])        { return gsl_cdf_poisson_P(args[0], args[1]); }
double poisson_Q(double args[])        { return gsl_cdf_poisson_Q(args[0], args[1]); }

double geo_pdf(double args[])          { return gsl_ran_geometric_pdf(args[0], args[1]); }
double geo_P(double args[])            { return gsl_cdf_geometric_P(args[0], args[1]); }
double geo_Q(double args[])            { return gsl_cdf_geometric_Q(args[0], args[1]); }

double hyper_pdf(double args[])        { return gsl_ran_hypergeometric_pdf(args[0], args[1], args[2], args[3]); }
double hyper_Q(double args[])          { return gsl_cdf_hypergeometric_Q(args[0], args[1], args[2], args[3]); }
double hyper_P(double args[])          { return gsl_cdf_hypergeometric_P(args[0], args[1], args[2], args[3]); }


enum distribution {
    NONE = -1,
    // CONTENIOUS
    Z_DIST,
    T_DIST,
    F_DIST,
    WEIBULL,
    EXPONENTIAL,

    // DISCRETE
    BINOMIAL,
    POISSON,
    GEOMETRIC,
    HYPERGEOMETRIC,
};

#define MAX_ARGS 4
int dist_nargs_table[] = {1, 2, 3, 3, 2, 3, 2, 2, 4};

struct config {
    bool left;
    bool right;
    bool inverse;
    enum distribution dist;
};

int main(int argc, char *argv[]) {

    struct config cfg = {
        .left = false,
        .right = false,
        .inverse = false,
        .dist = NONE,
    };

    char opt;
    while ((opt = getopt(argc, argv, OPTIONS DISTRIBUTIONS)) != -1) {
        switch (opt) {
            case 'i':
                cfg.inverse = true;
                break;
            case 'r':
                cfg.right = true;
                break;
            case 'b':
                cfg.dist = BINOMIAL;
                break;
            case 'e':
                cfg.dist = EXPONENTIAL;
                break;
            case 'f':
                cfg.dist = F_DIST;
                break;
            case 'g':
                cfg.dist = GEOMETRIC;
                break;
            case 'p':
                cfg.dist = POISSON;
                break;
            case 't':
                cfg.dist = T_DIST;
                break;
            case 'w':
                cfg.dist = WEIBULL;
                break;
            case 'y':
                cfg.dist = HYPERGEOMETRIC;
                break;
            case 'z':
                cfg.dist = Z_DIST;
                break;
            case 'h':
                char *help = USAGE
                "  Distributions:\n"
                "   -b Binomial distribution: r, p, n\n"
                "   -e Exponential distribution: x, mu\n"
                "   -f F-distribution: x, nu1, nu2\n"
                "   -g Geoemetric distribution: k, p\n"
                "   -p Poisson distribution: k, mu\n"
                "   -t Student-t distribution: x, nu\n"
                "   -w Weibull distribution: x, a, b\n"
                "   -y Hypergeoemtric distribution: k, n1, n2, t\n"
                "   -z Guassian (Normal) distribution: x\n"
                "  Modifiers:\n"
                "   -i Use the inverse of the specified distribution if possible\n"
                "   -l Use the left cumulative function (P)\n"
                "   -r Use the right cumulative function (Q) \n"
                " -h Show this help\n";
                printf(help, "%s");
                return 0;
        }
    }

    // default dist is normal
    if (cfg.dist == NONE) {
        cfg.dist = Z_DIST;
    }

    // set direction if not set expliclty
    if (cfg.left == cfg.right && cfg.left == false) {
        cfg.left = true;
        if (!IS_CONTENTIOUS(cfg.dist)) {
            cfg.right = true;
        }
    }

    // cfg.inverse must be false for discrete distributions
    if (!IS_CONTENTIOUS(cfg.dist) && cfg.inverse) {
        fprintf(stderr, "Can't find the inverse of discrete distribution\n");
    }

    // nargs
    double nums[MAX_ARGS];
    int nums_len = 0;
    char *err;
    for (int i = optind; i < argc; i++) {
        nums[nums_len] = strtod(argv[i], &err);
        nums_len++;
        if (*err != 0) {
            fprintf(stderr, "Error: %s cannot be interpreted as a number\n", argv[i]);
            return 1;
        }
    }

    if (nums_len != dist_nargs_table[cfg.dist]) {
        fprintf(stderr, "Invalid number of arguements exepcted %d, but got %d\n", dist_nargs_table[cfg.dist], nums_len);
        return 1;
    }

    // gsl quirk
    if (cfg.dist == Z_DIST) {
        nums[nums_len] = 1.0;
        nums_len++;
    }

    double result = 0;
    switch (cfg.dist) {
        case Z_DIST:
            result = CALL_CONTINUOUS(
                cfg,
                nums,
                z_cdf_P,
                z_cdf_Q,
                z_invcdf_P,
                z_invcdf_Q
            );
            break;
        case T_DIST:
            result = CALL_CONTINUOUS(
                cfg,
                nums,
                t_cdf_P,
                t_cdf_Q,
                t_invcdf_P,
                t_invcdf_Q
            );
            break;
        case F_DIST:
            result = CALL_CONTINUOUS(
                cfg,
                nums,
                f_cdf_P,
                f_cdf_Q,
                f_invcdf_P,
                f_invcdf_Q
            );
            break;
        case WEIBULL:
            result = CALL_CONTINUOUS(
                cfg,
                nums,
                weibull_cdf_P,
                weibull_cdf_Q,
                weibull_invcdf_P,
                weibull_invcdf_Q
            );
            break;

        case EXPONENTIAL:
            result = CALL_CONTINUOUS(
                cfg,
                nums,
                expo_pdf,
                expo_cdf_P,
                expo_cdf_Q,
                expo_invcdf_P
            );
            break;

        // DISCRETE
        case BINOMIAL:
            result = CALL_DISCRETE(
                cfg,
                nums,
                binomial_pdf,
                binomial_P,
                binomial_Q
            );

            break;

        case POISSON:
            result = CALL_DISCRETE(
                cfg,
                nums,
                poisson_pdf,
                poisson_P,
                poisson_Q
            );
            break;


        case GEOMETRIC:
            result = CALL_DISCRETE(
                cfg,
                nums,
                geo_pdf,
                geo_P,
                geo_Q
            );
            break;

        case HYPERGEOMETRIC:
            result = CALL_DISCRETE(
                cfg,
                nums,
                hyper_pdf,
                hyper_Q,
                hyper_P
            );
            break;
        // never happens
        default:
        break;
    }

    printf("%g\n", result);
}
