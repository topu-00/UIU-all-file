#include <stdio.h>
#include <string.h>
int main()
{
    char str[1000];
    int age;
    char line[10000];
    int read_line = 0, search_line;
    FILE *file;
    int add;
    printf("1.Add\n2.Detail\n");
    scanf("%d", &add);
    if (add <= 0 || add > 2)
    {
        printf("Invalid Input.\n");
        return 0;
    }

    if (add == 1)
    {
        file = fopen("problem_5.txt", "a");
        if (file == NULL)
        {
            printf("File does not exist.\n");
        }
        else
        {
            fflush(stdin);
            printf("Enter your name: ");
            fgets(str, 1000, stdin);
            str[strcspn(str, "\n")] = '\0';
            printf("Enter your age: ");
            scanf("%d", &age);
            fprintf(file, "Name: %s\nAge: %d\n", str, age);
            printf("File is written successfully.\n");
        }
        fclose(file);
    }
    else if (add == 2)
    {
        file = fopen("problem_5.txt", "r");
        if (file == NULL)
        {
            printf("File does not exist.\n");
        }
        else
        {
            printf("Enter Which line you want to read:");
            scanf("%d", &search_line);
            while (fgets(line, 10000, file))
            {
                read_line++;
                if (search_line == read_line || search_line + 1 == read_line)
                {
                    printf("%s", line);
                    if (search_line + 1 == read_line)
                    {
                        break;
                    }
                }
                fflush(stdin);
            }
            fclose(file);
        }
    }
    printf("---Thank You---\n");
    return 0;
}