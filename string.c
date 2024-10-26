#include "string.h"
#include <stdlib.h>

size_t strlen(const char *s)
{
    size_t i = 0;
    while (s[i] != '\0')
    {
        i++;                                                                
    }

    return i;
};

char *strcpy(char *dest, const char *src)
{
    strncpy(dest, src, strlen(src));

    return dest;
}

char *strncpy(char *dest, const char *src, size_t n)
{
    int i = 0;
    while (i < n)
    {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';

    return dest;
}

char *strdup(const char *src)
{
    char *new_str = (char*) malloc((strlen(src) + 1) *sizeof(char));
    new_str = strcpy(new_str, src);

    return new_str;
}

char *strcat(char *dest, const char *src)
{
    strncat(dest, src, strlen(src));

    return dest;
}

char *strncat(char *dest, const char *src, size_t n)
{
    int end = strlen(dest);
    int i = 0;

    while (i < n)
    {
        dest[end + i] = src[i];
        i++;
    }   

    dest[end + i] = '\0';

    return dest;
}

int strcmp(const char *left, const char *right)
{
    int l_size = strlen(left);
    int r_size = strlen(right);
    int max = l_size;

    if (r_size > max) {max = r_size;}

    return strncmp(left, right, max);
}

int strncmp(const char *left, const char *right, size_t n)
{
    int i = 0;
    while (i < n)
    {
        if (left[i]  < right[i]) {return -1;}
        else if (left[i] > right[i]) {return 1;}
        i++;
    }

    return 0;
}

char *revstrcpy(char *dest, const char *src)
{
    int len = strlen(src);

    for (int i = 0, j = len - 1; j >= 0; i++, j--)
    {
        dest[i] = src[j];
    }

    dest[len] = '\0';

    return dest;
}

size_t charsearch(const char *str, char c)
{
    for (size_t i = 0; i < strlen(str); i++)
    {
        if (str[i] == c) {return i;}
    }

    return -1;
}

size_t strsearch(const char *str, const char *substr)
{
    size_t sub_len = strlen(substr);

    for (size_t i = 0; i < strlen(str); i++)
    {
        if (str[i] == substr[0])
        {
            int j = 1;
            for (int k = i + 1; j < sub_len; j++, k++)
            {
                if (str[k] != substr[j]) {break;}
            }

            if (j == sub_len) {return i;}
        }
    }

    return -1;
}