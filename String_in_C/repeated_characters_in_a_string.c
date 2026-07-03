#include <stdio.h>
#include <string.h>
int main()
{
    char str[1000];
    fgets(str, 1000, stdin);
    str[strcspn(str, "\n")] = '\0';
    int len = strlen(str);
    for (int i = 0; i < len; i++) // this loop is use for access the all index of a string;
    {
        for (int j = i + 1; j < len; j++) // this loop is use for check repeated characters;
        {
            if (str[i] == str[j])
            {
                for (int k = j; k < len; k++) // this loop is use for remove repeated characters;
                {
                    str[k] = str[k + 1];
                }
            }
        }
    }
    printf("%s\n", str);
    return 0;
}