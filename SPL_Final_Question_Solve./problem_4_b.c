// problem 4(B).
#include <stdio.h>
int main()
{
    FILE *fp = fopen("bye.txt", "r");
    if (fp == NULL)
    {
        printf("File cannot be opened");
    }
    float a, b;
    while (fscanf(fp, "%f%f", &a, &b))
    {
        printf("%.2f\n", a + b);
        break;
    }
    fclose(fp);
    return 0;
}