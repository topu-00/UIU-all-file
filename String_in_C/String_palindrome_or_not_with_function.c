#include <stdio.h>
#include<string.h>
int main()
{
    char str1[1000];
    char str2[1000];
    fgets(str1,1000,stdin);
    str1[strcspn(str1,"\n")]='\0';//fgets function take newline(\n)as a input.So we remove newline;
    int len= strlen(str1);
    int k,i;
    for(i=len-1,k=0;i>=0;i--,k++)
    {
        str2[k]=str1[i];
    }
    str2[k]='\0';
    int flag=strcmp(str1,str2);
    if(flag==0)
    {
        printf("Palindrome\n");
    }
    else{
        printf("Not Palindrome\n");
    }
    return 0;
}
