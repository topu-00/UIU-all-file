#include <stdio.h>
#include <string.h>
int main()
{
    char str1[1000];
    char str2[1000];
    fgets(str1, 1000, stdin);
    fgets(str2, 1000, stdin);
    int a = strcmp(str1, str2);
    if (a == 0)
    {
        printf("String are same\n");
    }
    else
    {
        printf("String are not same\n");
    }
    return 0;
}
