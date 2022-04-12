#include "../headers/pipex.h"

void free_matrix(char **matrix)
{
    int i;

    i = -1;
    while (matrix[++i])
        free(matrix[i]);
    free(matrix);
}