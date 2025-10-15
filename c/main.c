/* ****************************************************************************************/
/* Author:           Luiz Otávio Mendes de Oliveira
/* Creation date:    15out2025
/* To exec:          make
/* ******************************************************************/

#include <stdio.h> // printf, puts, scanf
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include "io.h"
#include "solution.h"

int main()
{
    puts("Digite o tamanho do vetor: ");
    char *n_str = readline();
    char *n_endptr;                       // trash, not number
    int n = strtol(n_str, &n_endptr, 10); // number of elements > convert string to long

    if (n_endptr == n_str || *n_endptr != '\0')
    {
        exit(EXIT_FAILURE);
    }

    char *line = readline();
    char **arr_temp = split_string(line);

    int *arr = malloc(n * sizeof(int)); // array

    for (int i = 0; i < n; i++)
    {
        char *arr_item_endptr; // trash, not number
        char *arr_item_str = *(arr_temp + i);
        int arr_item = strtol(arr_item_str, &arr_item_endptr, 10);

        if (arr_item_endptr == arr_item_str || *arr_item_endptr != '\0')
        {
            exit(EXIT_FAILURE);
        }

        *(arr + i) = arr_item;
    }

    int retorno = solution(arr, n);

    // Próximo número inteiro não inserido no vetor:
    printf("%i\n", retorno);

    free(arr);
    free(line);
    free(n_str);
    free_split(arr_temp);
    return 0;
}