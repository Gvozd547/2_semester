#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void generation_matrix_distance(int **matrix_path, int number_nodes);
int factorial(int number);
void swap(int position1, int position2, int *mass);
int generation_combinations(int number_modes, int number_combination,
                            int **distance_matrix);
int path_cal(int number_modes, int *sequence, int **distance_matrix);
