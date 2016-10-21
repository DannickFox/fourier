// dft.c
// applies the direct fourier transform algorithm.

complex f_sum (int n, int N, double *x) {
    complex sum = {re: 0, im: 0};
    double alpha;
    for (int k = 0; k < N; k++) {
        alpha = -2 * M_PI * n * k / N;
        sum.re += x[k] * cos(alpha);
        sum.im += x[k] * sin(alpha);
    }
    return sum;
}

complex *directFourier (int N, double *x) {
    complex *DFT = malloc(sizeof(complex) * N);
    for (int n = 0; n < N; n++) {
        DFT[n] = f_sum(n, N, x);
    }
    return DFT;
}