#include <stdio.h>
void myFunction()
{
    printf("I just got executed!\n");
}
int my_function(/*int x , int y*/)
{
    int x, y;
    printf("Enter 2 Numer:");
    scanf("%d%d", &x, &y);
    return x + y;
}
int main()
{
    int a, b;
    myFunction();
    printf("%d\n", my_function());
    return 0;
}