// fft.c
// Fast fourier transform. (Radix-2 DIT)

complex *gen_fW (int N) {
    complex *W = malloc(sizeof(complex) * N);
    double alpha;
    for (int n = 0; n < N; n++) {
        if (n < N / 2) {
            alpha = -2 * M_PI * n / N;
            W[n] = (complex) {re: cos(alpha), im: sin(alpha)};
        } else {
            W[n] = c_neg(W[n - N / 2]);
        }
    }
    return W;
}

complex fft_sum (int n, int N, double *x, complex *W) {

}

complex *fastFourier(int N, double *x, complex *W) {
    complex *X = malloc(sizeof(complex) * N);
    
    for (int n = 0; n < N; n++) {
    }
    return X;
}
