#include <stdio.h>
int main (){
    int a;
    float b,c;
    char d;
    scanf("%d %f%c",&a,&b,&d);
    fflush(stdin);
    b=a+b; 
    c=a+d;           
    printf("%f %f",b,c);
    return 0;
}