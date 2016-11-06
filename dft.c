// dft.c
// Applies the direct fourier transform algorithm.

complex *gen_dW (int N) {
    // Generate W matrix.
    int n, k;
    complex *W = malloc(N * N * sizeof(complex));

    for (n = 0; n < N; n++) {
        for (k = 0; k < N; k++) {
            W[N * n + k] = c_eul(-2 * M_PI * n * k / N);
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