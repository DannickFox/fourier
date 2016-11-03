// fft.c
// Fast fourier transform. (Radix-2 DIT)

complex *gen_fW (int N) {
    // Generate W array.
    complex *W = malloc(sizeof(complex) * N);
    double alpha;
    for (int n = 0; n < N; n++) {
        if (n < N / 2) {
            alpha = -2 * M_PI * n / N;
            W[n] = c_eul(alpha);
        } else {
            W[n] = c_neg(W[n - N / 2]);
        }
    }
    return W;
}

int bitCount(int N) {
    int Nbits = 0;
    while ((N - 1) >> ++Nbits > 0);
    return Nbits;
}

int bitReverse (int N, int val) {
    // Bit reversal. N must be exponent of 2.
    int Nbits = bitCount(N);
    int reversed = 0, x;

    for (int i = 0; i < Nbits; i++) {
        x = (val << i) & (N >> 1);
        reversed |= x >> (Nbits - i - 1);
    }
    return reversed;
}

complex *fastFourier(int N, double *x, complex *W) {
    // Apply Fast Fourier Transform.
    complex *X = malloc(sizeof(complex) * N);
    int f_idx;
    for (int n = 0; n < N / 2; n++) {
        
    }
    return X;
}
