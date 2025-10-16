#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *normalize(const char *str)
{
    if (!str)
        return NULL;

    size_t length = strlen(str);
    char *str_normalize = malloc(length + 1); // +1 para o '\0'

    if (!str_normalize)
        return NULL;

    size_t j = 0;
    for (size_t i = 0; i < length; i++)
    {
        unsigned char c = (unsigned char)str[i];

        if (isspace(c))
            continue; // remove campos " "

        str_normalize[j] = tolower((unsigned char)c); // deixa todos minúsculos
        j++;
    }
    str_normalize[j] = '\0';
    return str_normalize;
}

int isAnagram(char *str_1, char *str_2)
{
    size_t length_1 = strlen(str_1);
    size_t length_2 = strlen(str_2);

    if (length_1 != length_2)
    {
        printf("Strings com tamanho diferente! \n");
        return 0;
    }

    int freq[256] = {0};

    for (size_t i = 0; str_1[i]; i++)
    {
        unsigned char c = str_1[i];
        freq[c]++;
    }

    for (size_t i = 0; str_2[i]; i++)
    {
        unsigned char c = str_2[i];
        freq[c]--;
    }

    for (int i = 0; i < 256; i++)
    {
        if (freq[i] != 0)
            return 0;
    }

    return 1;
}

int main()
{
    char *txt_1 = NULL, *txt_2 = NULL;
    size_t buffer_1 = 0, buffer_2 = 0;

    printf("Digite a primeira string: ");
    getline(&txt_1, &buffer_1, stdin);
    txt_1[strcspn(txt_1, "\n")] = '\0';

    printf("Digite a segunda string: ");
    getline(&txt_2, &buffer_2, stdin);
    txt_2[strcspn(txt_2, "\n")] = '\0';

    if (strlen(txt_1) == 0 || strlen(txt_2) == 0)
    {
        printf("String vazia NÃO é Anagrama! \n");
        free(txt_1);
        free(txt_2);
        return 0;
    }

    char *n_1 = normalize(txt_1);
    char *n_2 = normalize(txt_2);

    free(txt_1);
    free(txt_2);

    if (!n_1 || !n_2)
    {
        fprintf(stderr, "Erro: falha na normalização (malloc)\n");
        free(n_1);
        free(n_2);
        return 1;
    }

    if (strlen(n_1) == 0 || strlen(n_2) == 0)
    {
        printf("Após normalização, string vazia NÃO é Anagrama! \n");
    }
    else if (isAnagram(n_1, n_2))
        printf("A string digitada é um Anagrama! \n");
    else
        printf("A string digitada NÃO é um Anagrama! \n");

    free(n_1);
    free(n_2);
    return 0;
}
