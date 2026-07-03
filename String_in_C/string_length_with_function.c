#include <stdio.h>
#include <string.h>
int main()
{
    char str[1000000];
    fgets(str, 10000000, stdin);
    str[strcspn(str, "\n")] = '\0';
    /*
    fgets function take newline at the end of string.
    so we remove new line;
    */
    int length = strlen(str);
    printf("Length=%d\n", length);
    return 0;
}
