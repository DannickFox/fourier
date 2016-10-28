// fft.c
// Fast fourier transform. (Radix-2 DIT)

complex *gen_fW (int N) {
    // Generates complex W array of size N / 2.
    complex *W = malloc(sizeof(complex) * N);
    double alpha;
    for (int n = 0; n < N / 2; n++) {
        if (n < N / 2) {
            alpha = -2 * M_PI * n / N;
            W[n] = (complex) {re: cos(alpha), im: sin(alpha)};
        }
    }
    return W;
}

complex *fastFourier(int N, double *x, complex *W) {
    complex *X = malloc(sizeof(complex) * N);
    return X;
}
