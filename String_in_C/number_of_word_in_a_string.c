#include <stdio.h>
#include <string.h>
int main()
{
    char str[1000];
    fgets(str, 1000, stdin);
    str[strcspn(str, "\n")] = '\0';
    int isWord;
    if (str[0] == ' ')
    {
        isWord = 0;
    }
    else
    {
        isWord = 1;
    }
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] == ' ' && (str[i + 1] != ' ' || str[i + 1] != '\0'))
        {
            isWord++;
        }
    }
    printf("TotalWord: %d\n", isWord);
    return 0;
}