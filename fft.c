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

void butterfly (int n, int b, complex W, complex *X) {
    // Butterfly calculation. Values Xa and Xb temporarily hold current value.
    // Array X is directly manipulated.
    complex Xa = X[n],
            Xb = X[n + b];
    X[n] = c_sum(Xa, c_mul(W, Xb));
    X[n + b] = c_sub(Xa, c_mul(W, Xb));
}

complex *fastFourier(int N, double *x, complex *W) {
    // Apply Fast Fourier Transform. (Radix-2 DIT)
    complex *X = malloc(N * sizeof(complex));
    int b, i, j;
    
    for (b = 1; b <= N; b <<= 1) {
        // log2(N) stage loop
        for (i = 0; i < N; i += b) {
           // DFT loops. 
           if (b == 1) {
               // Time decimation.
               X[i] = (complex) {re: x[bitReverse(N, i)], im: 0};
           } else {
               // Butterfly calculation.
               b >>= 1; // Temporarily adjust b to use in butterfly.
               for (j = 0; j < b; j++) {
                   butterfly(j + i, b, W[j * bitReverse(N, b)], X);
               }
               b <<= 1; // Restore b value.
           }   
       }
    }
    return X;
}
