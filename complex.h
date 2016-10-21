// complex.h
// complex numbers

typedef struct complex {
    double re, im;
} complex;

complex c_sum(complex a, complex b) {
    // a + b = (x + jy) + (q + jp)
    complex sum = {
        re: a.re + b.re,
        im: a.im + b.im
    };
    return sum;
}

complex c_mul(complex a, complex b) {
    // a * b = (x + jy) * (q + jp)
    complex mul = {
        re: a.re * b.re - a.im * b.im,
        im: a.re * b.im + a.im * b.re
    };
    return mul;
}

double c_mag (complex x) {
    double mag = sqrt(x.re * x.re + x.im * x.im);
    return mag;
}

double c_ang (complex x) {
    double ang = atan(x.im / x.re);
    return ang;
}