#include "string.h"
#include <stdlib.h>

void menu();

char * get_value(const char *length_string, const char *string_type);

char *option_1(char *doc);

void option_2(const char *doc);

void option_3(const char *doc);

char *option_4(char *doc);

void menu()
{
    printf("\"1. Enter a Document\"\n\"2. View the Document\"\n\"3. Search the Document\"\n\"4. Append the Document\"\n\"5. Exit\"");
}

char * get_value(const char *length_string, const char *string_type)
{
    int length;
    printf("\"%s\"", length_string);

    scanf("%d", &length);
    getchar();

    char *string = (char *)malloc(((length + 1)* sizeof(char)));
    printf("\"%s\"", string_type);
    fgets(string, length + 1, stdin);

    return string;
}

char *option_1(char *doc)
{
    if (doc != NULL) {free(doc);}

    return get_value("Enter document length: ", "Enter document: ");
}

void option_2(const char *doc)
{
    if (doc == NULL) {printf("\"Error, no document has been entered!\n\"");}

    else {printf("\"%s\n\"", doc);}
}

void option_3(const char *doc)
{
    if (doc == NULL) {printf("\"Error, no document has been entered!\n\"");}

    else {
    char * term = get_value("Enter search length: ", "Enter search term: ");

    int result = strsearch(doc, term);
    free(term);

    if (result < 0) {printf("\"Search term not found\n\"");}
    else {printf("%d\n", result);}
    }
}

char *option_4(char *doc)
{
    char *txt = get_value("Enter additional text length: ", "Enter additional text: ");

    if (doc != NULL) {
        doc = strcat(doc, txt);
        
        free(txt);

        return doc;
    }

    else {return txt;}
}

void main()
{
    int option;
    char *document;
    while (option != 5) {
        menu();

        scanf("%d", &option);

        if (option == 1){document = option_1(document); }

        else if (option == 2){option_2(document);}

        else if (option == 3) {option_3(document);}

        else if (option == 4) {document = option_4(document);}

        else if (option != 5) {printf("\"Input is invalid\n\"");}
    }

    free(document);
}