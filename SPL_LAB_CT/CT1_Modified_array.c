//Question : Replace array index with a value ;

/*
This problem solved My friend Sadika.
She said me,"Here's a bug,try to solve it."
I find out the small bug and fixed it.
*/
#include <stdio.h>
int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int value[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", value[i]);
    }

    int s, r, count = 0;
    printf("\nEnter the number to search for: ");
    scanf("%d", &s);

    for (int i = 0; i < n; i++)
    {
        if (s != value[i])
        {
            count++;
            continue;
        }
        else if (s == value[i])
        {
            printf("Enter the number to replace with: ");
            scanf("%d", &r);
            for (int i = 0; i <= n; i++)
            {
                if (s == value[i])
                {
                    value[i] = r;
                }
            }
            printf("Modified array:\n");
            for (int i = 0; i < n; i++)
            {
                printf("%d\t", value[i]);
            }
        }
    }
    if (count == n)
    {
        printf("Number nai"); 
    }
    printf("\n");
    return 0;
}