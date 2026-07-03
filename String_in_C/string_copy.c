#include <stdio.h>
#include <string.h>
int main()
{
    char str[1000];
    char copy_str[1000];
    fgets(str, 1000, stdin);
    strcpy(copy_str, str);
    printf("String= %s\n", str);
    printf("Copy_string= %s\n", copy_str);
    return 0;
}
