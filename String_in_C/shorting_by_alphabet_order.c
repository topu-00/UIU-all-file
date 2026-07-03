#include <stdio.h>
#include <string.h>
#include <limits.h>
int main()
{
    int min = INT_MAX;
    char str[1000];
    fgets(str, 1000, stdin);        // take input;
    str[strcspn(str, "\n")] = '\0'; // remove new line ;
    int len = strlen(str);
    int array[len];
    for (int i = 0; str[i] != '\0'; i++)
    {
        array[i] = str[i]; // char to ASCII value;
    }
    int index = 0, temp;
    for (int i = 0; i < len; i++)
    {
        for (int j = i; j < len; j++)
        {
            if (array[j] < min)
            {
                min = array[j]; // find the minimum number and index;
                index = j;
            }
        }
        temp = array[i];
        array[i] = min;
        array[index] = temp; // shorting by minimum to maximum;
        min = INT_MAX;
        index = 0;
    }
    char str1[1000];
    int j;
    int i = 0;
    char str2[1000];
    for (int j = 0; j < len; j++)
    {
        if (array[j] > 32)
        {
            str2[i] = array[j]; // ASCII to char;
            i++;
        }
    }
    str2[i] = '\0';
    puts(str2);
    return 0;
}