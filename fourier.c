// fourier.c

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "complex.h"
#include "file_gen.c"
#include "file_read.c"
#include "fft.c"

int main (int argc, char **argv) {
    int N;
    double *sig;
    complex *FT, *W;

    if (argc > 1) {
        sig = file_read(argv[1], &N);
        W = gen_fW(N);

        if (sig && W) {
            FT = fastFourier(N, sig, W);
            if (FT) c_map_file_gen("fftOut", N, FT, ret_Re);
        } else printf("Memory error!");

        free(sig);
        free(W);
        free(FT);
    } else {
        printf("Error: No input file.\n");
    }
    printf("Done.");
    return 0;
}
