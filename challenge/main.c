#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int repeatString(char *str)
{
    int i, len = strlen(str); // retorna size_t
    int freq[256] = {0};
    for (i = 0; i < len; i++)
    {
        unsigned char c = str[i];
        if (freq[c] > 0)
        {
            return 1; // caractere repetido
        }
        freq[c]++;
    }
    return 0; // caracteres únicos
}

int main()
{
    char *txt = NULL;
    size_t length = 0; // valor dinâmico do tamanho do buffer da função getline
    printf("Digite a frase: ");
    getline(&txt, &length, stdin);  // lê conteúdo digitado pelo usuário
    txt[strcspn(txt, "\n")] = '\0'; // transforma o primeiro caractére \n em \0
    if(repeatString(txt)) printf("A string possui caracteres repetidos! \n");
    else printf("A string não possui caracteres repetidos! \n");
    free(txt);
    return 0;
}