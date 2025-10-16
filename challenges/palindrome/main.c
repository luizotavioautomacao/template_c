#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int isPalindrome(char *str)
{
    for (int i = 0; str[i]; i++)
    {
        str[i] = tolower((unsigned char)str[i]);
    }
    int i = 0, j = strlen(str) - 1;
    while (i < j)
    {
        if (str[i] != str[j])
        {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

int main()
{
    char *txt = NULL;
    size_t buffer = 0;
    printf("Digite a string: ");
    getline(&txt, &buffer, stdin);
    txt[(strcspn(txt, "\n"))] = '\0';
    if (strlen(txt) == 0)
    {
        printf("Nenhuma string foi digitada! \n");
        return 0;
    }
    if (isPalindrome(txt))
        printf("A string é um palindromo! \n");
    else
        printf("A string NÃO é um palindromo! \n");
    free(txt);
    return 0;
}