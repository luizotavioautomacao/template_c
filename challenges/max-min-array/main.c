#include <stdio.h>

void maxMinArray(int *vector, size_t length, int *max, int *min)
{
    *max = *min = vector[0];
    for (size_t i = 1; i < length; i++)
    {
        if (vector[i] < *min)
            *min = vector[i];
        if (vector[i] > *max)
            *max = vector[i];
    }
}

int main()
{
    int n = 0;
    printf("Digite a quantidade números: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        fprintf(stderr, "Entrada inválida! \n");
        return 1;
    }
    int vector[n];
    printf("Digite %d números inteiros: ", n);
    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &vector[i]) != 1)
        {
            fprintf(stderr, "Entrada inválida! \n");
            return 1;
        }
        if (i < n - 1)
            printf("Mais 1 número: ");
    }
    int max, min;
    maxMinArray(vector, n, &max, &min);
    printf("\nMaior número: %d \n", max);
    printf("Menor número: %d \n", min);
    return 0;
}