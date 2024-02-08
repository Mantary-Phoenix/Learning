#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *accept(char *a) // accepts a string and stores it using dynamic memory allocation
{
    char temp[100];
    int i;
    printf("Enter a string:\n");
    scanf("%s", temp);
    for (i = 0; temp[i] != '\0'; i++)
        ;
    a = (char *)malloc(sizeof(char) * i);
    strcpy(a, temp);
    return a;
}

void display(char *a) // displays a string
{
    printf("The string is: %s\n", a);
}

void delch(char *b, int p) // deletion of character from string using left shifting
{
    int i;
    for (i = p + 1; b[i] != '\0'; i++)
        b[i - 1] = b[i];
    b[i - 1] = '\0';
}

char *strdel(char *a, char c) // deletes the first occurence of the character
{
    char *b;
    int i = 0, len;
    for (len = 0; a[len] != '\0'; len++)
        ;                                   // finds the length of the string
    b = (char *)malloc(sizeof(char) * len); // dynamically allocates new memory of same length as a
    strcpy(b, a);                           // copies a to b
    while (b[i] != c && b[i] != '\0')       // finds the location of first occurence of the character
        i++;
    if (b[i] == '\0') // character not found
        return NULL;

    delch(b, i); // delete the charater from position i
    return b;
}

int main()
{
    int i;
    char *a, *b, ch;
    a = accept(a); // accepts a string
    printf("Enter the character: \n");
    scanf("%c", &ch);
    scanf("%c", &ch);
    b = strdel(a, ch); // deletes the character and stores the result in b
    if (b != NULL)     // b has a string
        display(b);
    else // b is empty
    {
        printf("Character not found.\n");
        display(a);
    }
}