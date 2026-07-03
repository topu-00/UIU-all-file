#include <stdio.h>
#include <string.h>
int main()
{
    char str[1000];
    int age;
    char line[10000];
    int read_line = 0, search_line;
    FILE *file;
    FILE *temp;
    int add;
    printf("1.Add\n2.Detail\n3.Delet\n4.Replace\n");
    scanf("%d", &add);
    if (add <= 0 || add > 4)
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
        else if (add == 2)
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
    else if (add == 3)
    {
        int read_line2 = 0, delet_line;
        char line2[10000];
        file = fopen("problem_5.txt", "r");
        temp = fopen("temp.txt", "w");
        if (temp == NULL)
        {
            printf("Error opening temp file.\n");
        }
        else
        {
            printf("Enter Which line you want to Delet:");
            scanf("%d", &delet_line);
            while (fgets(line2, 100, file))
            {
                read_line2++;
                if (read_line2 == delet_line || read_line2 == delet_line + 1)
                {
                    continue;
                }
                else
                {
                    fputs(line2, temp);
                }
            }
        }
        fclose(temp);
        fclose(file);
        if (rename("temp.txt", "problem_5.txt") == 0)
        {
            printf("Delet successfully.\n");
        }
        else
        {
            printf("Can't renaim the file.\n");
        }
    }
    else if (add == 4)
    {
        int read_line2 = 0, delet_line;
        char line2[10000];
        file = fopen("problem_5.txt", "r");
        temp = fopen("temp.txt", "w");
        if (temp == NULL)
        {
            printf("Error opening temp file.\n");
        }
        else
        {
            printf("Enter Which line you want to Replace:");
            scanf("%d", &delet_line);
            while (fgets(line2, 100, file))
            {
                read_line2++;
                if (read_line2 == delet_line)
                {
                    fflush(stdin);
                    printf("Enter your name: ");
                    fgets(str, 1000, stdin);
                    str[strcspn(str, "\n")] = '\0';
                    fprintf(temp, "Name: %s\n", str);
                }
                else if (read_line2 == delet_line + 1)
                {
                    fflush(stdin);
                    printf("Enter your age: ");
                    scanf("%d", &age);
                    fprintf(temp, "Age: %d\n", age);
                }
                else
                {
                    fputs(line2, temp);
                }
            }
        }
        fclose(temp);
        fclose(file);
        if (rename("temp.txt", "problem_5.txt") == 0)
        {
            printf("Replace successfully.\n");
        }
        else
        {
            printf("Can't renaim the file.\n");
        }
    }
    printf("---Thank You---\n");
    return 0;
}