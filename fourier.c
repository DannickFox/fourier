// fourier.c

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "complex.h"
#include "file_gen.c"
#include "file_read.c"
#include "dft.c"
#include "fft.c"

int main (int argc, char **argv) {
    int N;
    double *sig;
    complex *FT, *dW, *fW;
    clock_t start, end;

    if (argc > 1) {
        sig = file_read(argv[1], &N);
        dW = gen_dW(N);
        fW = gen_fW(N);

        if (sig && fW && dW) {
            printf("Sample size: %d elements.\n", N);
            start = clock();
            FT = fastFourier(N, sig, fW);
            end = clock();
            if (FT) {
                printf(
                    "FFT successfully excecuted in %lf ms.\n",
                    (double) (end - start) * 1000 / CLOCKS_PER_SEC
                );
                c_map_file_gen("fftOut", N, FT, c_mag);
                free(FT);
            }
        } else printf("Memory error!");

        free(sig);
        free(dW);
        free(fW);
    } else {
        printf("Error: No input file.\n");
    }
    printf("Done.");
    return 0;
}
