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
        printf("b = %i\n", b);
        // log2(N) stage loop
        for (i = 0; i < N; i += b) {
           printf("[%i]", i);
           if (b == 1) { // Time decimation.
               X[i] = (complex) {re: x[bitReverse(N, i)], im: 0};
               printf(":%.2lf: ", ret_Re(X[i]));
           } else { // Butterfly calculation.
               printf(" (");
               for (j = 0; j < b >> 1; j++) {
                   printf("%i:%i", j + i, j * bitReverse(N, b >> 1));
                   if (j + 1 < b >> 1) printf(", ");
                   butterfly(j + i, b >> 1, W[j * bitReverse(N, b >> 1)], X);
               }
               printf(") ");
           }
           
       }
       printf("\n");
    }
    return X;
}
