// file_read.c
// input file reader

#define STRLEN 8

double *file_read (char *filename, int *ar_size) {
    // Reads a file of floating point numbers.
    *ar_size = 0;
    FILE *ptr_f;
    char s_val[STRLEN];
    double *ar = malloc(sizeof(double));

    if (ptr_f = fopen(filename, "r")) {
        while (!feof(ptr_f)) {
            ar = realloc(ar, sizeof(double) * ++(*ar_size));
            fscanf(ptr_f, "%s\n", s_val);
            ar[*ar_size - 1] = atof(s_val);
        }
        fclose(ptr_f);
    } else {
        printf("Error! File \"%s\" not found!\n", filename);
        ar = NULL;
    }

    return ar;
}