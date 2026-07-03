#include <stdio.h>
#include <string.h>
int main()
{
    char str1[1000];
    char str2[1000];
    fgets(str1, 1000, stdin);
    int len = strlen(str1);
    int i, j;
    for (j = 0, i = len - 2; i >= 0;i--,j++)
    {
        str2[j] = str1[i];
    }
    str2[j] = '\n';//fgets function take newline(\n)as a input.So we need to initialize a newline on str2;
    str2[j+1] = '\0';
    int x = strcmp(str1, str2);
    if (x == 0)
    {
        printf("Palindrome\n");
    }
    else
    {
        printf("Not Palindrome\n");
    }
    return 0;
}