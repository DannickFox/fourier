// fourier.c

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "complex.h"
#include "dft.c"
#include "file_gen.c"
#include "file_read.c"

int main (int argc, char **argv) {
    int N;
    double *sig;
    complex *x;

    if (argc > 1) {
        if (sig = file_read(argv[1], &N)) {
            if (x = directFourier(N, sig)) {
                c_map_file_gen("fourierOut", N, x, c_mag);
                free(x);
            }
            free(sig);
        }
    } else {
        printf("Error: No input file.\n");
    }
    return 0;
}