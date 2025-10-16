#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int isVowel(char c)
{
    c = tolower((unsigned char)c);
    return ((c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'));
}

int main()
{
    char *txt = NULL;
    size_t buffer = 0;
    printf("Digite a string: ");
    getline(&txt, &buffer, stdin);
    txt[strcspn(txt, "\n")] = '\0';
    if (strlen(txt) == 0)
    {
        printf("Nenhuma string foi digitada! \n");
        return 0;
    }
    int count_vowel = 0;
    int count_consonant = 0;
    for (int i = 0; txt[i]; i++)
    {
        if (isalpha(txt[i]))
        {
            if (isVowel(txt[i]))
                count_vowel++;
            else
                count_consonant++;
        }
    }
    printf("Número de vogais: %i \n", count_vowel);
    printf("Número de consoantes: %i \n", count_consonant);
    free(txt);
    return 0;
}