#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isAnagram(char *str_1, char *str_2)
{
    int length_1 = strlen(str_1);
    int length_2 = strlen(str_2);

    if (length_1 != length_2)
        return 0;

    int freq[256] = {0};

    for (int i = 0; str_1[i]; i++)
    {
        unsigned char c = str_1[i];
        freq[c]++;
    }

    for (int i = 0; str_2[i]; i++)
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
    char *txt_1 = NULL;
    char *txt_2 = NULL;
    size_t buffer_1 = 0;
    size_t buffer_2 = 0;

    printf("Digite a primeira string: ");
    getline(&txt_1, &buffer_1, stdin);
    txt_1[strcspn(txt_1, "\n")] = '\0';

    printf("Digite a segunda string: ");
    getline(&txt_2, &buffer_2, stdin);
    txt_2[strcspn(txt_2, "\n")] = '\0';

    if (strlen(txt_1) == 0 || strlen(txt_2) == 0)
    {
        printf("String vazia NÃO é Anagrama! \n");
        return 0;
    }
    if (isAnagram(txt_1, txt_2))
        printf("A string digitada é um Anagrama! \n");
    else
        printf("A string digitada NÃO é um Anagrama! \n");

    free(txt_1);
    free(txt_2);
    return 0;
}
