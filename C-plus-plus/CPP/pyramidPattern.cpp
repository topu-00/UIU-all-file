#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++) // space
        {
            cout << " ";
        }
        for (int j = 1; j <= i + 1; j++) // 1st triangle
        {
            cout << j;
        }
        for (int j = i; j > 0; j--) // 2nd triangle
        {
            cout << j;
        }
        cout << endl; // space,1st triangle,2nd triangle this three loop print in same line and than print the next line ;
    }
}