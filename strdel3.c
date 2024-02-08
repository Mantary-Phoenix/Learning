#include <stdio.h>

void accept(char a[20], char *ch)
{
    printf("Enter a string:\n");
    scanf("%s", a);
    printf("Enter the character: \n");
    scanf("%c", ch);
    scanf("%c", ch);
}

void display(char a[20])
{
    printf("The string is: %s\n", a);
}

void delch(char a[20], int p)
{
    int i;
    for (i = p + 1; a[i] != '\0'; i++)
        a[i - 1] = a[i];
    a[i - 1] = '\0';
}

void strdel(char a[20], char c)
{
    int i = 0;
    while (a[i] != c && a[i] != '\0')
        i++;
    if (a[i] == '\0')
    {
        printf("Character not found.\n");
        return;
    }
    delch(a, i);
}

int main()
{
    int i;
    char a[20], ch;
    accept(a, &ch);
    strdel(a, ch);
    display(a);
}