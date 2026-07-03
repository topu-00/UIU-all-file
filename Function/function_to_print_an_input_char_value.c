#include <stdio.h>
void func(char k)
{
    printf("Value received from main: %c\n", k);
}

int main()
{
    char x;
    printf("Enter a Char : ");
    scanf("%c", &x);
    func(x);
    return 0;
}