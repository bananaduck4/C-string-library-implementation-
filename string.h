#ifndef STRING_HEADER_H
#define STRING_HEADER_H
#include <stdio.h>


size_t strlen(const char *s);

char *strcpy(char *dest, const char *src);

char *strncpy(char *dest, const char *src, size_t n);

char *strdup(const char *src);

char *strcat(char *dest, const char *src);

char *strncat(char *dest, const char *src, size_t n);

int strcmp(const char *left, const char *right);

int strncmp(const char *left, const char *right, size_t n);

char *revstrcpy(char *dest, const char *src);

size_t charsearch(const char *str, char c);

size_t strsearch(const char *str, const char *substr);

#endif