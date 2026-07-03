#include <stdio.h>
int main()
{
    int n;
    printf("Ente the index size:");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("Invalide array size; Enter a valid positive number;\n");
        return 0;
    }
    int array[n];
    printf("Enter the elements of array:⬇️\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    double even_sum = 0;
    int even_count = 0;

    double odd_sum = 0;
    int odd_count = 0;

    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            even_sum += array[i-1];
            even_count++;
        }
        else
        {
            odd_sum += array[i];
            odd_count++;
        }
    }
    if (even_count > 0)
    {
        double odd_avg = even_sum / even_count;
        printf("Average of odd indices: %.2f\n", odd_avg);
    }
    if (odd_count > 0)
    {
        double even_avg = even_sum / even_count;
        printf("Average of even indices: %.2f\n", even_avg);
    }
    printf("Total number of odd numbers: %d\n", odd_count);
    printf("Total number of even numbers: %d\n", even_count);
    
    return 0;
}