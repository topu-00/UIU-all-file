
//Done
// All done _ Final_NULL;
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
    struct student_info student, student_arr[1000];
    int student_count_detail = 0;
student_detail:
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
            student_count_detail++;
        }
        fclose(file); // file close;
    }
    int detail_flag = 0;
    int detail_index;
    printf(CYAN "\nStudent ID: " END);
    fgets(student.id, size, stdin);
    for (int i = 0; i < student_count_detail; i++)
    {
        if (strcmp(student_arr[i].id, student.id) == 0)
        {
            detail_index = i;
            detail_flag = 1;
            break;
        }
    }
    if (detail_flag == 0)
    {
        printf(RED "\nID not found !\n\n" END);
    }
    else if (detail_flag == 1)
    {
        printf("\nName  : %s", student_arr[detail_index].name);
        printf("ID    : %s", student_arr[detail_index].id);
        printf("Age   : %s", student_arr[detail_index].age);
        printf("Email : %s", student_arr[detail_index].email);
        printf("Phone : %s", student_arr[detail_index].phone);
        printf("CT    : %s", student_arr[detail_index].result.ct);
        printf("Mid   : %s", student_arr[detail_index].result.mid);
        printf("Final : %s\n", student_arr[detail_index].result.final);
    }
    int option_detail;
    printf(YELLOW "1.Main menu.\n2.Search again.\n3.Exit.\n" END);
    scanf("%d", &option_detail);
    if (option_detail == 1)
    {
        fflush(stdin);
        // goto menu;
    }
    else if (option_detail == 2)
    {
        fflush(stdin);
        goto student_detail;
    }
    else
    {
        printf(MAGENTA "\n-----Thank You-----\n\n" END);
        return 0;
    }
    return 0;
}