#include <iostream>
using namespace std;

int main()//O(n);
{
    int arr[] = {3, -4, 5, 4, -1, 7, -8};
    int currentSum = 0;
    int maxSum = INT_MIN;
    for (int i = 0; i < 7; i++)
    {
        currentSum += arr[i];
        maxSum = max(currentSum, maxSum);
        if (currentSum < 0)
            currentSum = 0;
    }
    cout << "Max Subarray Sum: " << maxSum << endl;
    return 0;
}