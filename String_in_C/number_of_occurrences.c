#include <stdio.h>
#include <string.h>
int main()
{
    char str1_in[1000];
    char str1_s[1000] = {' '};

    char str2_in[1000];
    char str2_s[1000] = {' '};

    int count = 0;
    int same_word = 0;

    fgets(str1_in, 1000, stdin);
    str1_in[strcspn(str1_in, "\n")] = '\0';

    strcat(str1_in, str1_s);
    strcat(str1_s, str1_in);

    fgets(str2_in, 1000, stdin);
    str2_in[strcspn(str2_in, "\n")] = '\0';

    strcat(str2_in, str2_s);
    strcat(str2_s, str2_in);

    int len = strlen(str1_s);
    int len2 = strlen(str2_s);

    for (int i = 0; str1_s[i] != '\0'; i++)
    {
        for (int j = i, k = 0; str2_s[k] != '\0'; j++, k++)
        {
            if (str1_s[j] == str2_s[k])
            {
                count++;
            }
        }
        if (count == len2)
        {
            same_word++;
        }
        count = 0;
    }
    printf("%d\n", same_word);
    return 0;
}