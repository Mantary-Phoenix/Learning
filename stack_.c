#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 4

void push(int s[MAX_SIZE], int *top, int elem)
{
    if (*top == MAX_SIZE - 1)
    {
        printf("Stack overflow.\n");
        return;
    }
    (*top)++;
    s[*top] = elem;
}

int pop(int s[MAX_SIZE], int *top)
{
    int elem;
    if (*top == -1)
    {
        printf("Stack underflow.\n");
    }
    else
    {
        elem = s[*top];
        (*top)--;
        return elem;
    }
}

void display(int s[MAX_SIZE], int top)
{
    int i;
    if (top == -1)
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements are: \n");
    for (i = (top); i >= 0; i--)
    {
        printf("%d\n", s[i]);
    }
}

void palindrome(int s[MAX_SIZE], int top)
{
    int s1[MAX_SIZE], s2[MAX_SIZE], top1 = -1, top2 = -1;
    int flag = 1, elem, i;
    if (top == -1)
    {
        printf("Stack is empty.\n");
        return;
    }
    for (i = 0; i <= top; i++)
        push(s1, &top1, s[i]);
    while (top1 != -1)
    {
        push(s2, &top2, pop(s1, &top1));
    }
    for (i = 0; i <= top; i++)
    {
        if (s[i] != s2[i])
        {
            flag = 0;
            break;
        }
    }
    if (flag)
        printf("Stack is a palindrom.\n");
    else
        printf("Stack is not a palindrome.\n");
}

void status(int s[MAX_SIZE], int top)
{
    int used;
    used = top + 1;
    printf("%d locations of stack are used.\n", used);
    printf("%d locations of stack are free.\n", MAX_SIZE - used);
}

int main()
{
    int s[MAX_SIZE], elem, top = -1;
    int ch, temp;
    while (1)
    {
        printf("\n1. Push\n"
               "2. Pop\n"
               "3. Display\n"
               "4. Palindrom.\n"
               "5. Status\n"
               "6. Exit.\n");
        printf("Enter the choice: \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element to be inserted: \n");
            scanf("%d", &elem);
            push(s, &top, elem);
            break;
        case 2:
            if (top == -1)
                temp = -1;
            else
                temp = 0;
            elem = pop(s, &top);
            if (temp != -1)
                printf("%d was deleted.\n", elem);
            break;
        case 3:
            display(s, top);
            break;
        case 4:
            palindrome(s, top);
            break;
        case 5:
            status(s, top);
            break;
        default:
            exit(0);
        }
    }
}