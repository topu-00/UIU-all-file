#include <stdio.h>
#include <string.h>
int main()
{
    char str[1000];
    fgets(str, 1000, stdin);
    str[strcspn(str, "\n")] = '\0';
    int len = strlen(str);
    char ch, ch1;
    scanf("%c", &ch);
    if (ch >= 'A' && ch <= 'Z')
    {
        ch1 = ch + 32;
    }
    else
    {
        ch1 = ch - 32;
    }
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        if (str[i] == ch || str[i] == ch1)
        {
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}