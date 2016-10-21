// fourier.c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "complex.h"
#include "dft.c"
#include "file_gen.c"

double *step (int N, int a, int b, double A) {
    double *sig = malloc(sizeof(double) * N);
    for (int i = 0; i < N; i++) {
        if (i < a) {
            sig[i] = 0;
        } else if (i < b) {
            sig[i] = A;
        } else {
            sig[i] = 0;
        }
    }
    return sig;
}

double *sigSen (int N, double T, double freq, double A) {
    double *sig = malloc(sizeof(double) * N);
    for (int i = 0; i < N; i++) {
        sig[i] = A * sin(2 * M_PI * freq * i * T);
    }
    return sig;
}

int main (void) {
    int samples = 1000;
    double *sig;
    complex *x;

    if (sig = sigSen(samples, 1e-6, 1e3, 1)) {
        file_gen("stepOut.txt", samples, sig);

        if (x = directFourier(samples, sig)) {
            c_map_file_gen("fourierOut.txt", samples, x, c_mag);
            free(x);
        }
        free(sig);
    }

    return 0;
}