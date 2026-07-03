#include <stdio.h>
#include <string.h>
int main()
{
    char str1[1000];
    char str2[1000];
    fgets(str1, 1000, stdin);
    str1[strcspn(str1,"\n")]='\0';
    int len = strlen(str1);
    int i, j;
    for (j = 0, i = len - 1; i >= 0; j++, i--)
    {
        str2[j] = str1[i];
    }
    str2[j]='\0';
    puts(str2);
    return 0;
}
