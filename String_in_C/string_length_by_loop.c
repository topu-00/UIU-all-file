#include <stdio.h>
#include<string.h>
int main()
{
    char str[100];
    int i = 0;
    fgets(str, 100, stdin);
    for (; str[i] != '\0';)
    {
        i++;
    }
    puts(str);
    printf("Length=%d\n",i);
    return 0;
}
