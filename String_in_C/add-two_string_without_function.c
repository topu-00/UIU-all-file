#include<stdio.h>
#include<string.h>
int main()
{
    char str1[1000];
    char str2[1000];
    fgets(str1,1000,stdin);
    str1[strcspn(str1,"\n")]='\0';
    fgets(str2,1000,stdin);
    str2[strcspn(str2,"\n")]='\0';
    int len = strlen(str1);
    int j=0;
    while(str2[j]!='\0')
    {
        str1[len+j]=str2[j];
        j++;
    }
    puts(str1);
    return 0;
}