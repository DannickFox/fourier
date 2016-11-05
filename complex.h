// complex.h
// Complex number functions.

typedef struct complex {
    double re, im;
} complex;

complex c_neg (complex a) {
    // negates the complex number.
    return (complex) {
        re: -a.re,
        im: -a.im
    };
}

complex c_sum (complex a, complex b) {
    // a + b = (x + jy) + (q + jp)
    return (complex) {
        re: a.re + b.re,
        im: a.im + b.im
    };
}

complex c_sub (complex a, complex b) {
    // a - b = (x + jy) - (q + jp)
    return (complex) {
        re: a.re - b.re,
        im: a.im - b.im
    };
}

complex c_mul (complex a, complex b) {
    // a * b = (x + jy) * (q + jp)
    return (complex) {
        re: a.re * b.re - a.im * b.im,
        im: a.re * b.im + a.im * b.re
    };
}

complex c_scale (double x, complex A) {
    return (complex) {
        re: A.re * x,
        im: A.im * x
    };
}

complex c_eul (double x) {
    return (complex) {
        re: cos(x),
        im: sin(x)
    };
}

double c_mag (complex x) {
    return sqrt(x.re * x.re + x.im * x.im);
}

double c_ang (complex x) {
    return atan(x.im / x.re);
}

double ret_Re (complex A) {
    return A.re;
}

double ret_Im (complex A) {
    return A.im;
}