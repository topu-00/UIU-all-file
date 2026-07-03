#include <iostream>
using namespace std;
int main() //O(n²);
{
    int n = 7;
    int arr[] = {3, -4, 5, 4, -1, 7, -8};
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int CurrentSum = 0;
        for (int j = i; j < n; j++)
        {
            CurrentSum += arr[j];
            maxSum = max(CurrentSum, maxSum);
        }
    }
    cout << endl;
    cout << "Maximum Subarray Sum: " << maxSum << endl;
    cout << endl;
}