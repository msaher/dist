#ifndef UTILS_h
#define UTILS_h
#define ERROR(...) fprintf(stderr, __VA_ARGS__), exit(1)
#define ERROR_USAGE() ERROR("Usage: %s [-lir] [-z | -t] n1 [n2] [n3] [n4]\n", argv[0])
#endif
