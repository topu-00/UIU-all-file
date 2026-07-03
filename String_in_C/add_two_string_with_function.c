#include <stdio.h>
#include <string.h>
int main()
{
    char str1[1000];
    char str2[1000];
    fgets(str1, 1000, stdin);
    fgets(str2, 1000, stdin);
    strcat(str1, str2);
    printf("%s\n", str1);
    return 0;
}
