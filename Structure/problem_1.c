#include <stdio.h>
// Global structure.
struct person
{
    int age;
    float salary;
};
int main()
{
    struct person person_1, person_2;
    person_1.age = 20;
    person_1.salary = 10000.50;
    printf("Person1 : \n");
    printf("Age= %d\n", person_1.age);
    printf("Salary= %.2f\n", person_1.salary);
    person_2.age = 18;
    person_2.salary = 1000.60;
    printf("Person2 : \n");
    printf("Age= %d\n", person_2.age);
    printf("Salary= %.2f\n", person_2.salary);
    return 0;
}