# fourier
Direct and Radix-2 FFT implementations for Discrete Fourier Transform.

This program takes a file with valid floating point numbers of a signal
sample of 2^n elements. The program applies the DFT and FFT algorithms
given and creates two output files of each implementation. The amount of
time taken for each algorithm is also measured for comparison.

### Files
- fourier.c: Entry point.
- complex.h: Header file for complex number operations.
- dft.c: Slow Discrete Fourier Transform algorithm.
- fft.c: Fast Fourier Transform algorithm (Radix-2 DIT)
