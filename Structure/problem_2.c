#include <stdio.h>
struct person
{
    int age;
    float salary;
};
int main()
{
    struct person person1, person2;
    printf("Enter Information for Person1: \n");
    printf("Enter Age : ");
    scanf("%d", &person1.age);
    printf("Enter salary : ");
    scanf("%f", &person1.salary);

    printf("\n\nEnter Information for Person2: \n");
    printf("Enter Age : ");
    scanf("%d", &person2.age);
    printf("Enter salary : ");
    scanf("%f", &person2.salary);

    printf("\n\nPerson1 Information : \n");
    printf("Age: %d\n", person1.age);
    printf("Salary: %.2f\n", person1.salary);
    printf("\n\nPerson2 Information : \n");
    printf("Age: %d\n", person2.age);
    printf("Salary: %.2f\n", person2.salary);

    return 0;
}