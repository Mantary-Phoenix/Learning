#include <stdio.h>

void accept(char a[20], char *ch) // accepts a string and a character
{
    printf("Enter a string:\n");
    scanf("%s", a);
    printf("Enter the character: \n");
    scanf("%c", ch);
    scanf("%c", ch);
}

void display(char a[20]) // displays a string
{
    printf("The string is: %s\n", a);
}

void delch(char a[20], int p) // deletion of character from string using left shifting
{
    int i;
    for (i = p + 1; a[i] != '\0'; i++)
        a[i - 1] = a[i];
    a[i - 1] = '\0';
}

void strdel(char a[20], char c) // deletes the first occurence of the character
{
    int i = 0;
    while (a[i] != c && a[i] != '\0') // finds the location of first occurence of the character
        i++;
    if (a[i] == '\0') // character not found
    {
        printf("Character not found.\n");
        return;
    }
    delch(a, i); // delete the charater from position i
}

int main()
{
    int i;
    char a[20], ch;
    accept(a, &ch); // accepts a string and a character
    strdel(a, ch);  // deletes the character
    display(a);
}