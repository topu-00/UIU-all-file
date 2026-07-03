#include <stdio.h>
#include <string.h>
int main()
{
    char ch;
    FILE *file;
    file = fopen("Problem_5.txt", "r");
    if (file == NULL)
    {
        printf("File does not exist.\n");
    }
    else
    {
        printf("File is open.\n");
        while ((ch=fgetc(file))!=EOF)
        {
            printf("%c", ch);   
        }
        fclose(file);
    }
    return 0;
}