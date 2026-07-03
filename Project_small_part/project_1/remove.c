// all done final_NULL;
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define size 100
// Define color codes
#define END "\x1B[0m"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define BLUE "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN "\x1B[36m"
#define WHITE "\x1B[37m"
struct mark
{
    char ct[size];
    char mid[size];
    char final[size];
};

struct student_info
{
    char name[size];
    char id[size];
    char age[size];
    char email[size];
    char phone[size];
    struct mark result;
};
int main()
{
    FILE *file;
    FILE *temp;
    struct student_info student, student_arr[1000];
    int student_count_for_remove = 0;
delete_student:

    file = fopen("data.txt", "r");
    if (file == NULL)
    {
        printf("Error Opening Data r File 1\n");
    }
    else
    {
        for (int i = 0; i < 1000; i++)
        {
            fgets(student_arr[i].name, size, file);
            fgets(student_arr[i].id, size, file);
            fgets(student_arr[i].age, size, file);
            fgets(student_arr[i].email, size, file);
            fgets(student_arr[i].phone, size, file);
            fgets(student_arr[i].result.ct, size, file);
            fgets(student_arr[i].result.mid, size, file);
            fgets(student_arr[i].result.final, size, file);

            if (strcmp(student_arr[i].name, "") == 0)
            {
                break;
            }
            student_count_for_remove++;
        }
        fclose(file);
    }

    int delete_flag = 0;
    printf(CYAN "\nStudent ID: " END);
    fgets(student.id, size, stdin);
    for (int i = 0; i < student_count_for_remove; i++)
    {
        if (strcmp(student_arr[i].id, student.id) == 0)
        {
            for (int j = i; j < student_count_for_remove; j++)
            {
                student_arr[j] = student_arr[j + 1];
            }
            delete_flag = 1;
            printf(GREEN "\n\nPermanently Delete Student !\n\n" END);
            break;
        }
    }
    if (delete_flag == 0)
    {
        printf(RED "\nID not found !\n\n" END);
    }

    temp = fopen("temp.txt", "a");
    if (file == NULL)
    {
        printf("Error Opening Data a File 1\n");
    }
    else
    {
        for (int i = 0; i < student_count_for_remove; i++)
        {
            fputs(student_arr[i].name, temp);
            fputs(student_arr[i].id, temp);
            fputs(student_arr[i].age, temp);
            fputs(student_arr[i].email, temp);
            fputs(student_arr[i].phone, temp);
            fputs(student_arr[i].result.ct, temp);
            fputs(student_arr[i].result.mid, temp);
            fputs(student_arr[i].result.final, temp);
        }
        fclose(temp);
    }

    rename("temp.txt", "data.txt");

    int option_add;
    printf(YELLOW "1.Main menu.\n2.Delete again.\n3.Exit.\n" END);
    scanf("%d", &option_add);
    if (option_add == 1)
    {
        fflush(stdin);
        // goto menu;
    }
    else if (option_add == 2)
    {
        fflush(stdin);
        goto delete_student;
    }
    else
    {
        printf(MAGENTA "\n-----Thank You-----\n\n" END);
        return 0;
    }
    return 0;
}