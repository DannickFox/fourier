#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

#include "complex.h"
#include "dft.c"
#include "fft.c"

double *gen_x (int N) {
    double *x = malloc(N * sizeof(double));
    for (int i = 0; i < N; i++) {
        x[i] = (double) i;
    }
    return x;
}

int main(void) {
    double *x, elapsedTime;
    complex *F, *W;
    LARGE_INTEGER frequency, t1, t2;

    QueryPerformanceFrequency(&frequency);

    for (int N = 1; N <= 1 << 16; N <<= 1) {
        x = gen_x(N);
        W = gen_fW(N);

        QueryPerformanceCounter(&t1);
        F = fastFourier(N, x, W);
        QueryPerformanceCounter(&t2);

        elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;

        free(x); free(W); free(F);
        printf("%i\t%lf\n", N, elapsedTime);
    }

    return 0;
}