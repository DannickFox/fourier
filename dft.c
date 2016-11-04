// dft.c
// Applies the direct fourier transform algorithm.

complex *gen_dW (int N) {
    // Generate W matrix.
    int n, k;
    double alpha;
    complex *W = malloc(N * N * sizeof(complex));

    for (n = 0; n < N; n++) {
        for (k = 0; k < N; k++) {
            alpha = -2 * M_PI * n * k / N;
            W[N * n + k] = c_eul(alpha);
        }
    }
    return W;
}

complex *directFourier (int N, double *x, complex *W) {
    // Apply direct discrete Fourier Transform.
    complex *X = malloc(sizeof(complex) * N);
    int n, k;

    for (n = 0; n < N; n++) {
        X[n] = (complex) {re: 0, im: 0};
        for (k = 0; k < N; k++) {
            // X[n] = X[n] + x[k] * W[n][k]
            X[n] = c_sum(X[n], c_scale(x[k], W[N * n + k]));
        }
    }
    return X;
}