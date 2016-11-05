// fft.c
// Fast fourier transform. (Radix-2 DIT)

complex *gen_fW (int N) {
    // Generate W array.
    complex *W = malloc(sizeof(complex) * N / 2);
    double alpha;
    for (int n = 0; n < N / 2; n++) {
        W[n] = c_eul(-2 * M_PI * n / N);
    }
    return W;
}

int bitReverse (int N, int val) {
    // Bit reversal. N must be exponent of 2.
    int Nbits = 0,
        reversed = 0, x;
    while ((N - 1) >> ++Nbits > 0); // count number of bits.

    for (int i = 0; i < Nbits; i++) {
        x = (val << i) & (N >> 1);
        reversed |= x >> (Nbits - i - 1);
    }
    return reversed;
}

void butterfly (int N, int n, int b, complex *X, complex *W) {
    int m = 0;
    X[n] = c_sum(X[n], X[n + b]);
    X[n] = c_sum(X[n], c_mul(c_neg(W[m]), X[n + b]));
}

complex *fastFourier(int N, double *x, complex *W) {
    // Apply Fast Fourier Transform. (Radix-2 DIT)
    complex *X = malloc(N * sizeof(complex));
    int n, b, k;

    for (b = 1; b < N; b <<= 1) {
       for (n = 0; n < N; n += 1) {
           if (b == 1) { // Initial division in time.
               X[n] = (complex) {re: x[bitReverse(N, n)], im: 0};
           }
       }
    }
    return X;
}
