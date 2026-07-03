#include <stdio.h>
void swapArray(int A[], int B[], int n, int m)
{
    for (int i = 0; i < (n > m ? n : m); i++)
    {
        int temp = A[i];
            A[i] = B[i];
            B[i] = temp;
    }
    printf("Elements of array A after swapping: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    printf("Elements of array B after swapping: ");
    for (int i = 0; i < m; i++) {
        printf("%d ", B[i]);
    }
    printf("\n");
}
int main()
{
    int n;
    printf("Enter the array A size : ");
    scanf("%d", &n);
    int arrayA[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the value of index %d : ", i);
        scanf("%d", &arrayA[i]);
    }
    int m;
    printf("Enter the array B size : ");
    scanf("%d", &m);
    int arrayB[m];
    for (int i = 0; i < m; i++)
    {
        printf("Enter the value of index %d : ", i);
        scanf("%d", &arrayB[i]);
    }
    swapArray(arrayA,arrayB,n,m);
    return 0;
}