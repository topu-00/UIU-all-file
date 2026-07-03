
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
    FILE *temp;
    struct student_info student, student_arr[1000];
    int student_count_for_mark = 0;
again_add_mark:
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
            student_count_for_mark++;
        }
        fclose(file);
    }
    printf(CYAN "\nStudent ID: " END);
    int student_index_no = 0;
    int student_exist_flag = 0;
    fgets(student.id, size, stdin);

    for (int i = 0; i < student_count_for_mark; i++)
    {
        if (strcmp(student_arr[i].id, student.id) == 0)
        {
            student_index_no = i;
            student_exist_flag = 1;
        }
    }

    if (student_exist_flag == 1) // Student exist;
    {
        fflush(stdin);
        int option_mark;
        int invalid = 0;
        printf(YELLOW "\n1.CT Mark.\n2.Mid Mark.\n3.Final Mark.\n4.All Mark.\n" END);
    invalid_option:
        scanf("%d", &option_mark);
        fflush(stdin);

        if (option_mark == 1) // add CT mark
        {
            fflush(stdin);
            printf("Enter CT Mark: ");
            fgets(student_arr[student_index_no].result.ct, size, stdin);
            temp = fopen("temp.txt", "a");
            if (temp == NULL)
            {
                printf("Error Opening temp a File 1\n");
            }

            else
            {
                for (int i = 0; i < student_count_for_mark; i++)
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
            printf(GREEN "\n\n---Mark added successfully---\n\n" END);
        }
        else if (option_mark == 2) // add Mid mark
        {
            fflush(stdin);
            printf("Enter Mid Mark: ");
            fgets(student_arr[student_index_no].result.mid, size, stdin);
            temp = fopen("temp.txt", "a");
            if (temp == NULL)
            {
                printf("Error Opening temp a File 1\n");
            }
            else
            {

                for (int i = 0; i < student_count_for_mark; i++)
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
            printf(GREEN "\n\n---Mark added successfully---\n\n" END);
        }
        else if (option_mark == 3) // add final mark;
        {
            fflush(stdin);
            printf("Enter Final Mark: ");
            fgets(student_arr[student_index_no].result.final, size, stdin);
            temp = fopen("temp.txt", "a");
            if (temp == NULL)
            {
                printf("Error Opening temp a File 1\n");
            }
            else
            {
                for (int i = 0; i < student_count_for_mark; i++)
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
            printf(GREEN "\n\n---Mark added successfully---\n\n" END);
        }
        else if (option_mark == 4) // add all mark ;
        {
            fflush(stdin);
            printf("Enter CT Mark: ");
            fgets(student_arr[student_index_no].result.ct, size, stdin);
            fflush(stdin);
            printf("Enter Mid Mark: ");
            fgets(student_arr[student_index_no].result.mid, size, stdin);
            fflush(stdin);
            printf("Enter Final Mark: ");
            fgets(student_arr[student_index_no].result.final, size, stdin);
            fflush(stdin);
            temp = fopen("temp.txt", "a");
            if (temp == NULL)
            {
                printf("Error Opening File temp 1\n");
            }
            else
            {

                for (int i = 0; i < student_count_for_mark; i++)
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
            printf(GREEN "\n\n---Marks added successfully---\n\n" END);
        }
        else
        {
            invalid++;
            if (invalid > 2)
            {
                printf(GREEN "\nYou Can't Try Again.\n" END);
                printf(MAGENTA "\n-----Thank You-----\n\n" END);
                return 0;
            }
            printf(RED "Try Again.\n" END);
            fflush(stdin);
            goto invalid_option;
        }
    }
    else // student not found;
    {
        printf(RED "Student Not Found !\n" END);
    }

    int option_add_mark;
    printf(YELLOW "1.Main menu.\n2.Mark Add again.\n3.Exit.\n" END);
    scanf("%d", &option_add_mark);
    if (option_add_mark == 1)
    {
        fflush(stdin);
        // goto menu;
    }
    else if (option_add_mark == 2)
    {
        fflush(stdin);
        goto again_add_mark;
    }
    else
    {
        printf(MAGENTA "\n-----Thank You-----\n\n" END);
        return 0;
    }
    return 0;
}