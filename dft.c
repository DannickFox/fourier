// dft.c
// Applies the direct fourier transform algorithm.

complex **gen_W (int N) {
    // Generate W matrix.
    int n, k;
    double alpha;
    complex **W = malloc(N * sizeof(complex *));

    for (n = 0; n < N; n++) {
        W[n] = malloc(N * sizeof(complex));
        for (k = 0; k < N; k++) {
            alpha = -2 * M_PI * n * k / N;
            W[n][k] = (complex) {re: cos(alpha), im: sin(alpha)};
        }
    }
    return W;
}

complex *directFourier (int N, double *x, complex **W) {
    // Apply direct discrete Fourier Transform.
    complex *X = malloc(sizeof(complex) * N);
    int n, k;

    for (n = 0; n < N; n++) {
        X[n] = (complex) {re: 0, im: 0};
        for (k = 0; k < N; k++) {
            X[n] = c_sum(X[n], c_scale(x[k], W[n][k]));
        }
    }
    return X;
}