//done;

// All done _ final_NULL;

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
    struct student_info student, student_arr[10000];

    strcpy(student.result.ct, "0");
    strcpy(student.result.mid, "0");
    strcpy(student.result.final, "0");

Add_student:
    file = fopen("data.txt", "r");
    if (file == NULL)
    {
        printf("Error Opening Data r File 1\n");
    }
    else
    {

        for (int i = 0; i < 10000; i++)
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
        }
        fclose(file);
    }

    printf(CYAN "\nStudent Name: " END);
    fgets(student.name, size, stdin);

    printf(CYAN "\nStudent ID: " END);
student_id:
    fgets(student.id, size, stdin);

    for (int i = 0; i < 10000; i++)
    {
        if (strcmp(student_arr[i].name, "") == 0)
        {
            break;
        }
        else
        {
            if (strcmp(student_arr[i].id, student.id) == 0)
            {
                printf(RED "\nStudent ID already exists.\n" END);
                printf(CYAN "\nEnter a Valid Student ID: " END);
                goto student_id;
            }
        }
    }
    printf(CYAN "\nStudent Age: " END);
    fgets(student.age, size, stdin);
    printf(CYAN "\nStudent Email: " END);
    fgets(student.email, size, stdin);
    printf(CYAN "\nStudent Phone: " END);
    fgets(student.phone, size, stdin);

    file = fopen("data.txt", "a");

    fputs(student.name, file);
    fputs(student.id, file);
    fputs(student.age, file);
    fputs(student.email, file);
    fputs(student.phone, file);
    fputs(student.result.ct, file);
    fputs("\n", file);
    fputs(student.result.mid, file);
    fputs("\n", file);
    fputs(student.result.final, file);
    fputs("\n", file);

    fclose(file);
    printf(GREEN "\n\n---Student added successfully---\n\n" END);
    int option_add;
    printf(YELLOW "1.Main menu.\n2.Add again.\n3.Exit.\n" END);
    scanf("%d", &option_add);
    if (option_add == 1)
    {
        fflush(stdin);
        // goto menu;
    }
    else if (option_add == 2)
    {
        fflush(stdin);
        goto Add_student;
    }
    else
    {
        printf(MAGENTA "\n-----Thank You-----\n\n" END);
        return 0;
    }
    return 0;
}