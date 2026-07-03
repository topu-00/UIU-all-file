#include<stdio.h>
int main()
{
    char ch;
    int n;
    // take a char as input
    printf("Enter a Char: ");
    scanf("%c",&ch);
    // take a number as input
    printf("Enter a Num: ");
    scanf("%d",&n);
    if (ch>='A' && ch<='Z') // this condition for uppercase⬇️
    {
        for (int i = 1; i <=n; i++)
    {
        printf("%c\t",ch);
        ch++;
        if (ch>'Z')
        { 
            ch='A';
        }
    }
    }
    //this is for lowercase⬇️
    else{
    for (int i = 1; i <=n; i++)
    {
        printf("%c\t",ch);
        ch++;
        if (ch>'z')
        {
            ch='a';
        }
    }
    }
    printf("\n");
    return 0;
}