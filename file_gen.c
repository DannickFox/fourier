// file_gen.c
// Output file generator.
void file_gen (char *f_name, int ar_len, double *ar) {
    FILE *f;
    if (f = fopen(f_name, "w")) {
        for (int i = 0; i < ar_len; i++) {
            fprintf(f, "%lf\n", ar[i]);
        }
        fclose(f);
        printf("File \"%s\" created.\n", f_name);
    } else {
        printf("File error.\n");
    }
}

void c_map_file_gen (char *f_name, int ar_len, complex *ar, double (*fcn)(complex)) {
    FILE *f;
    if (f = fopen(f_name, "w")) {
        for (int i = 0; i < ar_len; i++) {
            fprintf(f, "%lf\n", fcn(ar[i]));
        }
        fclose(f);
        printf("File \"%s\" created.\n", f_name);
    } else {
        printf("File error.\n");
    }
}