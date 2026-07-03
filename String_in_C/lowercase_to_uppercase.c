#include <stdio.h>
#include <string.h>
int main()
{
    char str[1000];
    fgets(str, 1000, stdin);
    str[strcspn(str, "\n")] = '\0';
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32;
        }
    }
    puts(str);
    return 0;
}