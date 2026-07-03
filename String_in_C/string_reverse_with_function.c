#include <stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char str1[1000];
    fgets(str1,1000,stdin);
    printf("Main_string= %s\n",str1);
    strrev(str1);
    printf("Reverse_string= %s\n",str1);
    return 0;
}
