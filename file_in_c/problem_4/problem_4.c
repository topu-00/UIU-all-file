/*
    How to write or read something on file (Add With previous data).
*/
#include <stdio.h>
#include <string.h>
int main()
{
    char str1[1000];
    printf("Enter your  Name: ");
    fgets(str1, 1000, stdin);
    str1[strcspn(str1, "\n")] = '\0';
    FILE *file;
    file = fopen("problem_4.txt", "a");
    if (file == NULL)
    {
        printf("File dose not exist.\n");
    }
    else
    {
        printf("File is opend.\n");
        fputs(str1, file);
        fputs("\n", file);
        printf("File is written successfully.\n");
        fclose(file);
    }
    return 0;
}