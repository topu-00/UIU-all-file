#include <stdio.h>
int main()
{
    int n;
    printf("Enter the array size: ");
    scanf("%d", &n);
    char array[n];
    for (int i = 0; i < n; i++)
    {
        fflush(stdin);
        printf("Enter The Value of index %d: ", i);
        scanf("%c", &array[i]);
    }
    int count=0;
    for (int i = 0; i < n; i++)
    {
        if (array[i] == 'A' || array[i] == 'E' || array[i] == 'I' || array[i] == 'O' || array[i] == 'U')
        {
            count++;
        }
    }
    printf("Count: %d\n",count);
    return 0;
}