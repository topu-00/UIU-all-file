// all done final;

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
struct user_email_pass
{
    char name[size];
    char id[size];
    char phone[size];
    char email[size];
    char pass[size];
};

int main()
{
    FILE *user_pass;

    struct user_email_pass user1,user[1000];
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
    printf(CYAN "\n----Login----\n\n" END);
    printf("ID: ");
    fgets(user1.id, size, stdin);

    printf("\nPassWord: ");
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
        printf("Access\n"); // add,delete,detail,
    }

    else
    {
        printf(RED "\nStudent Account Not Found !\n" END);
        int option;
        printf(YELLOW "\n1.Create a Account.\n2.Try again.\n3.Exit.\n" END);
        scanf("%d", &option);

        if (option == 1)
        {
            fflush(stdin);
            printf(GREEN "-----Create your Account-----\n\n" END);

            printf("Name: ");
            fgets(user1.name, size, stdin);

            printf("ID: ");
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
                    printf(RED "\nLogin Id is already being used by another account !\n\n" END);
                    printf("Enter a valid ID: ");
                    fflush(stdin);
                    goto id_check00;
                }
            }

            printf("Phone: ");
            fgets(user1.phone, size, stdin);

            printf("Email: ");
            fgets(user1.email, size, stdin);

            printf("PassWord: ");
            fgets(user1.pass, 100, stdin);

            user_pass = fopen("User_passWord.txt", "a");
            fputs(user1.name, user_pass);
            fputs(user1.id, user_pass);
            fputs(user1.phone, user_pass);
            fputs(user1.email, user_pass);
            fputs(user1.pass, user_pass);
            fclose(user_pass);

            int login_option;
            printf(MAGENTA "\n1.Login Page.\n2.Exit.\n" END);
            scanf("%d", &login_option);
            if (login_option == 1)
            {
                fflush(stdin);
                goto login_user;
            }
            else
            {
                printf(MAGENTA "\n-----Thank You-----\n\n" END);
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
            printf(MAGENTA "\n-----Thank You-----\n\n" END);
            return 0;
        }
    }

    return 0;
}