#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define size 100
// Define color codes
struct user_email_pass
{
    char name[size];
    char id[size];
    char phone[size];
    char email[size];
    char pass[size];
};
struct email_pass
{
    char email[size];
    char pass[size];
};
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
    printf("\n");
    printf("\t");

    printf("---------- WeLcOme To OuR eLeArNiNg MaNaGeMeNt SySteM ----------");

    printf("\n");

    FILE *pass;
    FILE *file;
    FILE *temp;
    FILE *user_pass;
    int person_count = 0;
    struct user_email_pass user1, user[1000];
    struct email_pass person1, person[1000];
    struct student_info student, student_arr[1000];
    int option_User;

    printf("\n");
    printf("\t\t\t\t");
    printf("1.Admin.");
    printf("\n");
    printf("\t\t\t\t");
    printf("2.User.");
    printf("\n");
    printf("\t\t\t\t");

    scanf("%d", &option_User);
    fflush(stdin);
    if (option_User == 1)
    {
        // pass check start;
    login:
        pass = fopen("passWord.txt", "r");

        if (pass == NULL)
        {
            printf("\t\t\t\t");
            printf("Error Opening PassWord r File 1\n");
        }

        else
        {

            for (int i = 0; i < 1000; i++)
            {
                fgets(person[i].email, size, pass);
                fgets(person[i].pass, size, pass);
                if (strcmp(person[i].email, "") == 0)
                {
                    break;
                }
                person_count++;
            }
            fclose(pass);
        }
        printf("\n");
        printf("\t\t\t");
        printf("    ----Login----\n\n");
        printf("\t\t\t\t");
        printf("Email: ");
        fgets(person1.email, size, stdin);
        printf("\t\t\t\t");
        printf("PassWord: ");
        fgets(person1.pass, 100, stdin);

        int person_check = 0;
        for (int i = 0; i < person_count; i++)
        {
            if ((strcmp(person[i].email, person1.email) == 0) && (strcmp(person[i].pass, person1.pass)) == 0)
            {
                person_check = 1;
                break;
            }
        }

        if (person_check == 1)
        {
            int option_menu;

        menu:
            printf("\n\t\t\t\t1.Add Student.\n\t\t\t\t2.Remove Student.\n\t\t\t\t3.Add Mark.\n\t\t\t\t4.Student Detail.\n\t\t\t\t5.All Student Details.\n");
            printf("\t\t\t\t");
        menu1:
            scanf("%d", &option_menu);
            fflush(stdin);

            if (option_menu == 1)
            {
                // add start

                strcpy(student.result.ct, "0");
                strcpy(student.result.mid, "0");
                strcpy(student.result.final, "0");

            Add_student:
                file = fopen("data.txt", "r");
                if (file == NULL)
                {
                    printf("\t\t\t\t");
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
                    }
                    fclose(file);
                }

                printf("\n\t\t\t\tStudent Name: ");
                fgets(student.name, size, stdin);

                printf("\n\t\t\t\tStudent ID: ");
            student_id:
                fgets(student.id, size, stdin);

                for (int i = 0; i < 1000; i++)
                {
                    if (strcmp(student_arr[i].name, "") == 0)
                    {
                        break;
                    }
                    else
                    {
                        if (strcmp(student_arr[i].id, student.id) == 0)
                        {
                            printf("\n\t\t\t\tStudent ID already exists.\n");
                            printf("\n\t\t\t\tEnter a Valid Student ID: ");
                            goto student_id;
                        }
                    }
                }
                printf("\n\t\t\t\tStudent Age: ");
                fgets(student.age, size, stdin);
                printf("\n\t\t\t\tStudent Email: ");
                fgets(student.email, size, stdin);
                printf("\n\t\t\t\tStudent Phone: ");
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
                printf("\n\n\t\t\t\t---Student added successfully---\n\n");
                int option_add;
                printf("\t\t\t\t1.Main menu.\n\t\t\t\t2.Add again.\n\t\t\t\t3.Exit.\n");
                printf("\t\t\t\t");
                scanf("%d", &option_add);
                if (option_add == 1)
                {
                    fflush(stdin);
                    goto menu;
                }
                else if (option_add == 2)
                {
                    fflush(stdin);
                    goto Add_student;
                }
                else
                {
                    printf("\n\t\t\t\t-----Thank You-----\n\n");
                    return 0;
                }
                // add end
            }
            else if (option_menu == 2)
            {
                // remove start ;

                int student_count_for_remove = 0;
            delete_student:

                file = fopen("data.txt", "r");
                if (file == NULL)
                {
                    printf("\t\t\t\tError Opening Data r File 1\n");
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
                printf("\n\t\t\t\tStudent ID: ");
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
                        printf("\n\n\t\t\t\tPermanently Delete Student !\n\n");
                        break;
                    }
                }
                if (delete_flag == 0)
                {
                    printf("\n\t\t\t\tID not found !\n\n");
                }

                temp = fopen("temp.txt", "a");
                if (file == NULL)
                {
                    printf("\t\t\t\tError Opening Data a File 1\n");
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
                printf("\t\t\t\t1.Main menu.\n\t\t\t\t2.Delete again.\n\t\t\t\t3.Exit.\n");
                printf("\t\t\t\t");
                scanf("%d", &option_add);
                if (option_add == 1)
                {
                    fflush(stdin);
                    goto menu;
                }
                else if (option_add == 2)
                {
                    fflush(stdin);
                    goto delete_student;
                }
                else
                {
                    printf("\n\t\t\t\t-----Thank You-----\n\n");
                    return 0;
                }
                // remove end ;
            }
            else if (option_menu == 3)
            {
                // mark start

                int student_count_for_mark = 0;
            again_add_mark:
                file = fopen("data.txt", "r");
                if (file == NULL)
                {
                    printf("\t\t\t\tError Opening Data r File 1\n");
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
                printf("\n\t\t\t\tStudent ID: ");
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
                    printf("\n\t\t\t\t1.CT Mark.\n\t\t\t\t2.Mid Mark.\n\t\t\t\t3.Final Mark.\n\t\t\t\t4.All Mark.\n");
                invalid_option:
                    printf("\t\t\t\t");
                    scanf("%d", &option_mark);
                    fflush(stdin);

                    if (option_mark == 1) // add CT mark
                    {
                        fflush(stdin);
                        printf("\t\t\t\tEnter CT Mark: ");
                        fgets(student_arr[student_index_no].result.ct, size, stdin);
                        temp = fopen("temp.txt", "a");
                        if (temp == NULL)
                        {
                            printf("\t\t\t\tError Opening temp a File 1\n");
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
                        printf("\n\n\t\t\t\t---Mark added successfully---\n\n");
                    }
                    else if (option_mark == 2) // add Mid mark
                    {
                        fflush(stdin);
                        printf("\t\t\t\tEnter Mid Mark: ");
                        fgets(student_arr[student_index_no].result.mid, size, stdin);
                        temp = fopen("temp.txt", "a");
                        if (temp == NULL)
                        {
                            printf("\t\t\t\tError Opening temp a File 1\n");
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
                        printf("\n\n\t\t\t\t---Mark added successfully---\n\n");
                    }
                    else if (option_mark == 3) // add final mark;
                    {
                        fflush(stdin);
                        printf("\t\t\t\tEnter Final Mark: ");
                        fgets(student_arr[student_index_no].result.final, size, stdin);
                        temp = fopen("temp.txt", "a");
                        if (temp == NULL)
                        {
                            printf("\t\t\t\tError Opening temp a File 1\n");
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
                        printf("\n\n\t\t\t\t---Mark added successfully---\n\n");
                    }
                    else if (option_mark == 4) // add all mark ;
                    {
                        fflush(stdin);
                        printf("\t\t\t\tEnter CT Mark: ");
                        fgets(student_arr[student_index_no].result.ct, size, stdin);
                        fflush(stdin);
                        printf("\t\t\t\tEnter Mid Mark: ");
                        fgets(student_arr[student_index_no].result.mid, size, stdin);
                        fflush(stdin);
                        printf("\t\t\t\tEnter Final Mark: ");
                        fgets(student_arr[student_index_no].result.final, size, stdin);
                        fflush(stdin);
                        temp = fopen("temp.txt", "a");
                        if (temp == NULL)
                        {
                            printf("\t\t\t\tError Opening File temp 1\n");
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
                        printf("\n\n\t\t\t\t---Marks added successfully---\n\n");
                    }
                    else
                    {
                        invalid++;
                        if (invalid > 2)
                        {
                            printf("\n\t\t\t\tYou Can't Try Again.\n");
                            printf("\n\t\t\t\t-----Thank You-----\n\n");
                            return 0;
                        }
                        printf("\t\t\t\tTry Again.\n");
                        fflush(stdin);
                        goto invalid_option;
                    }
                }
                else // student not found;
                {
                    printf("\n\t\t\t\tStudent Not Found !\n\n");
                }

                int option_add_mark;
                printf("\t\t\t\t1.Main menu.\n\t\t\t\t2.Mark Add again.\n\t\t\t\t3.Exit.\n");
                printf("\t\t\t\t");
                scanf("%d", &option_add_mark);
                if (option_add_mark == 1)
                {
                    fflush(stdin);
                    goto menu;
                }
                else if (option_add_mark == 2)
                {
                    fflush(stdin);
                    goto again_add_mark;
                }
                else
                {
                    printf("\n\t\t\t\t-----Thank You-----\n\n");
                    return 0;
                }
                // mark end
            }
            else if (option_menu == 4)
            {
                // detail start

                int student_count_detail = 0;
            student_detail:
                file = fopen("data.txt", "r");
                if (file == NULL)
                {
                    printf("\t\t\t\tError Opening Data r File 1\n");
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
                printf("\n\t\t\t\tStudent ID: ");
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
                    printf("\n\t\t\t\tID not found !\n\n");
                }
                else if (detail_flag == 1)
                {
                    printf("\n\t\t\t\tName  : %s", student_arr[detail_index].name);
                    printf("\t\t\t\tID    : %s", student_arr[detail_index].id);
                    printf("\t\t\t\tAge   : %s", student_arr[detail_index].age);
                    printf("\t\t\t\tEmail : %s", student_arr[detail_index].email);
                    printf("\t\t\t\tPhone : %s", student_arr[detail_index].phone);
                    printf("\t\t\t\tCT    : %s", student_arr[detail_index].result.ct);
                    printf("\t\t\t\tMid   : %s", student_arr[detail_index].result.mid);
                    printf("\t\t\t\tFinal : %s\n", student_arr[detail_index].result.final);
                }
                int option_detail;
                printf("\t\t\t\t1.Main menu.\n\t\t\t\t2.Search again.\n\t\t\t\t3.Exit.\n");
                printf("\t\t\t\t");
                scanf("%d", &option_detail);
                if (option_detail == 1)
                {
                    fflush(stdin);
                    goto menu;
                }
                else if (option_detail == 2)
                {
                    fflush(stdin);
                    goto student_detail;
                }
                else
                {
                    printf("\n\t\t\t\t-----Thank You-----\n\n");
                    return 0;
                }
                // detail end
            }
            else if (option_menu == 5)
            {
                // all detail start

                int student_count_all_detail = 0;
                file = fopen("data.txt", "r");
                if (file == NULL)
                {
                    printf("\t\t\t\tError Opening Data r File 1\n");
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
                        student_count_all_detail++;
                    }
                    fclose(file);
                }

                if (student_count_all_detail == 0)
                {
                    printf("\n\t\t\t\tStudent Not Found !\n\n");
                }

                for (int i = 0; i < student_count_all_detail; i++)
                {
                    printf("\n\t\t\t\tName  : %s", student_arr[i].name);
                    printf("\t\t\t\tID    : %s", student_arr[i].id);
                    printf("\t\t\t\tAge   : %s", student_arr[i].age);
                    printf("\t\t\t\tEmail : %s", student_arr[i].email);
                    printf("\t\t\t\tPhone : %s", student_arr[i].phone);
                    printf("\t\t\t\tCT    : %s", student_arr[i].result.ct);
                    printf("\t\t\t\tMid   : %s", student_arr[i].result.mid);
                    printf("\t\t\t\tFinal : %s\n", student_arr[i].result.final);
                }

                int option_detail;
                printf("\t\t\t\t1.Main menu.\n\t\t\t\t2.Exit.\n");
                printf("\t\t\t\t");
                scanf("%d", &option_detail);
                if (option_detail == 1)
                {
                    fflush(stdin);
                    goto menu;
                }
                else
                {
                    printf("\n\t\t\t\t-----Thank You-----\n\n");
                    return 0;
                }
                // all detail end
            }
            else
            {
                printf("\n\t\t\t\tInvalid Input !\n\n");
                printf("\t\t\t\tTry again: ");
                fflush(stdin);
                goto menu1;
            }
        }

        else
        {
            int option;
            printf("\n\t\t\t\t1.Create a Account.\n\t\t\t\t2.Try again.\n\t\t\t\t3.Exit.\n");
            printf("\t\t\t\t");
            scanf("%d", &option);

            if (option == 1)
            {
                fflush(stdin);
                printf("\t\t\t\t-----Create your Account-----\n\n");

                printf("\t\t\t\tEmail: ");
                fgets(person1.email, size, stdin);

                printf("\t\t\t\tPassWord: ");
                fgets(person1.pass, 100, stdin);

                pass = fopen("passWord.txt", "a");
                if (pass == NULL)
                {
                    printf("\t\t\t\tError Opening PassWord a File 1\n");
                }

                fputs(person1.email, pass);
                fputs(person1.pass, pass);
                fclose(pass);

                int login_option;
                printf("\n\t\t\t\t1.Login Page.\n\t\t\t\t2.Exit.\n");
                printf("\t\t\t\t");
                scanf("%d", &login_option);
                if (login_option == 1)
                {
                    fflush(stdin);
                    goto login;
                }
                else
                {
                    printf("\n\t\t\t\t-----Thank You-----\n\n");
                    return 0;
                }
            }

            else if (option == 2)
            {
                fflush(stdin);
                goto login;
            }

            else
            {
                printf("\n\t\t\t\t-----Thank You-----\n\n");
                return 0;
            }
        }

        // password check end;
    }
    else if (option_User == 2)
    {
        // user all code start ;

        int person_count = 0;
    login_user:
        user_pass = fopen("User_passWord.txt", "r");
        for (int i = 0; i < 1000; i++)
        {

            fgets(user[i].name, size, user_pass);
            fgets(user[i].id, size, user_pass);
            fgets(user[i].phone, size, user_pass);
            fgets(user[i].email, size, user_pass);
            fgets(user[i].pass, size, user_pass);

            if (strcmp(user[i].email, "") == 0)
            {
                break;
            }
            person_count++;
        }
        printf("\t\t\t    ----Login----\n\n");
        printf("\t\t\t\tID: ");
        fgets(user1.id, size, stdin);

        printf("\n\t\t\t\tPassWord: ");
        fgets(user1.pass, 100, stdin);

        int person_check = 0;
        for (int i = 0; i < person_count; i++)
        {
            if ((strcmp(user[i].id, user1.id) == 0) && (strcmp(user[i].pass, user1.pass)) == 0)
            {
                person_check = 1;
                break;
            }
        }

        if (person_check == 1)
        {

            file = fopen("data.txt", "r");
            if (file == NULL)
            {
                printf("\t\t\t\tError Opening Data r File 1\n");
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
                }
                fclose(file);
            }
            int student_index1 = 0;
            int student_check3 = 0;
            for (int i = 0; i < 1000; i++)
            {
                if (strcmp(student_arr[i].name, "") == 0)
                {
                    break;
                }
                else if (strcmp(student_arr[i].id, user1.id) == 0)
                {
                    student_index1 = i;
                    student_check3 = 1;
                    break;
                }
            }
            if (student_check3 == 1)
            {
                printf("\n\t\t\t\tName  : %s", student_arr[student_index1].name);
                printf("\t\t\t\tID    : %s", student_arr[student_index1].id);
                printf("\t\t\t\tAge   : %s", student_arr[student_index1].age);
                printf("\t\t\t\tEmail : %s", student_arr[student_index1].email);
                printf("\t\t\t\tPhone : %s", student_arr[student_index1].phone);
                printf("\t\t\t\tCT    : %s", student_arr[student_index1].result.ct);
                printf("\t\t\t\tMid   : %s", student_arr[student_index1].result.mid);
                printf("\t\t\t\tFinal : %s\n", student_arr[student_index1].result.final);
                printf("\n\t\t\t\t-----Thank You-----\n\n");
            }
            else
            {
                printf("\n\t\t\t\tAdmin Not Added You In Our Database !\n\n");
                return 0;
            }
        }

        else
        {
            printf("\n\t\t\t\tStudent Account Not Found !\n");
            int option;
            printf("\n\t\t\t\t1.Create a Account.\n\t\t\t\t2.Try again.\n\t\t\t\t3.Exit.\n");
            printf("\t\t\t\t");
            scanf("%d", &option);

            if (option == 1)
            {
                fflush(stdin);
                printf("\t\t\t\t-----Create your Account-----\n\n");

                printf("\t\t\t\tName: ");
                fgets(user1.name, size, stdin);

                printf("\t\t\t\tID: ");
            id_check00:
                fgets(user1.id, size, stdin);

                for (int i = 0; i < 10000; i++)
                {
                    if (strcmp(user[i].email, "") == 0)
                    {
                        break;
                    }
                    else if (strcmp(user[i].id, user1.id) == 0)
                    {
                        printf("\n\t\t\t\tLogin Id is already being used by another account !\n\n");
                        printf("\t\t\t\tEnter a valid ID: ");
                        fflush(stdin);
                        goto id_check00;
                    }
                }

                printf("\t\t\t\tPhone: ");
                fgets(user1.phone, size, stdin);

                printf("\t\t\t\tEmail: ");
                fgets(user1.email, size, stdin);

                printf("\t\t\t\tPassWord: ");
                fgets(user1.pass, 100, stdin);

                user_pass = fopen("User_passWord.txt", "a");
                fputs(user1.name, user_pass);
                fputs(user1.id, user_pass);
                fputs(user1.phone, user_pass);
                fputs(user1.email, user_pass);
                fputs(user1.pass, user_pass);
                fclose(user_pass);

                int login_option;
                printf("\n\t\t\t\t1.Login Page.\n\t\t\t\t2.Exit.\n");
                printf("\t\t\t\t");
                scanf("%d", &login_option);
                if (login_option == 1)
                {
                    fflush(stdin);
                    goto login_user;
                }
                else
                {
                    printf("\n\t\t\t\t-----Thank You-----\n\n");
                    return 0;
                }
            }

            else if (option == 2)
            {
                fflush(stdin);
                goto login_user;
            }

            else
            {
                printf("\n\t\t\t\t-----Thank You-----\n\n");
                return 0;
            }
        }

        // user all code end;
    }
    else
    {
        printf("\n\t\t\t\tInvalid Input !\n\n");
        return 0;
    }
    return 0;
}