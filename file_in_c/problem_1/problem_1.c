/*
    How to open and close file .
*/
#include <stdio.h>
int main()
{
    FILE *test;
    test = fopen("Problem_1.txt", "w");
    if (test == NULL)
    {
        printf("File dose not exist\n");
    }
    else
    {
        printf("File is opene\n");
        fclose(test);
    }
    return 0;
}