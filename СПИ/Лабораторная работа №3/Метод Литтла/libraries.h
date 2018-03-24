#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void gen_matrix_distance(int size, double ***matrix);
int subtraction_matrix(int size, double **matrix);
void calc_fine(int size, double **matrix, int *index_i, int *index_j,
               int *res_fine);
void malloc_for_matrix(int size, double ***matrix);
void copy_matrix_for_m1(int size, int index_i, int index_j, double **matrix_in,
                        double ***matrix_out);
void copy_matrix_for_m2(int size, int index_i, int index_j, double **matrix_in,
                        double ***matrix_out);
void removal(int size, int index_i, int index_j, double ***matrix);
void printf_matrix(int size, double **matrix);
void recursion(double *record, int limit, int size, double **matrix_m1);
