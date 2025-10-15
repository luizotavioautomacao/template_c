/* ******************************************************************/
/* Author:           Luiz Otávio Mendes de Oliveira
/* Creation date:    15out2025
/* To exec:          make
/* ******************************************************************/

#include <stdio.h>     // I/O padrão: printf, puts, scanf (saída formatada)
#include <stdlib.h>    // utilidades gerais: malloc/free, strtol, exit
#include <assert.h>    // assert para verificações em tempo de desenvolvimento (não usado aqui)
#include <limits.h>    // limites de tipos inteiros (ex.: INT_MAX) (não usado aqui)
#include <math.h>      // funções matemáticas (ex.: pow, sqrt) (não usado aqui)
#include <stdbool.h>   // tipo bool, valores true/false
#include <stddef.h>    // definições básicas (ex.: size_t, NULL)
#include <stdint.h>    // inteiros de largura fixa (ex.: uint32_t) (não usado aqui)
#include <string.h>    // manipulação de strings (ex.: strtok/strlen), usada nos helpers
#include "io.h"        // helpers de entrada: readline, split_string, free_split
#include "solution.h"  // assinatura da função solution()

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