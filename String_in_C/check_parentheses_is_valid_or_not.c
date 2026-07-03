#include <stdio.h>
#include <string.h>
int main()
{
    char str[1000];
    fgets(str, 1000, stdin);
    str[strcspn(str, "\n")] = '\0';
    int open1 = 0;
    int open2 = 0;
    int open3 = 0;
    int close1 = 0;
    int close2 = 0;
    int close3 = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] == '(')
        {
            open1++;
        }
        else if (str[i] == ')')
        {
            close1++;
        }
        else if (str[i] == '{')
        {
            open2++;
        }
        else if (str[i] == '}')
        {
            close2++;
        }
        else if (str[i] == '[')
        {
            open3++;
        }
        else if (str[i] == ']')
        {
            close3++;
        }
    }
    if (open1 == close1 && open2 == close2 && open3 == close3)
    {
        printf("VALID\n");
    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}