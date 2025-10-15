#include "io.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *readline(void)
{
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char *data = malloc(alloc_length);

    while (1)
    {
        char *cursor = data + data_length;
        char *line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line)
        {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n')
        {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!line)
        {
            break;
        }
    }

    if (data_length && data[data_length - 1] == '\n')
    {
        data[data_length - 1] = '\0';
        data = realloc(data, data_length);
    }
    else
    {
        data = realloc(data, data_length + 1);
        data[data_length] = '\0';
    }

    return data;
}

char **split_string(char *str)
{
    char **splits = NULL;
    char *token = strtok(str, " ");

    int spaces = 0;

    while (token)
    {
        char **tmp = realloc(splits, sizeof(char *) * (spaces + 1));
        if(!tmp){ free(splits); return NULL; }
        splits = tmp;
        splits[spaces++] = token;
        token = strtok(NULL, " ");
    }

    return splits;
}

void free_split(char **splits)
{
    free(splits);
}


