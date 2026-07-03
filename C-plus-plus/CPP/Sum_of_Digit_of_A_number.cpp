#include <iostream>
using namespace std;
int sumOfdigit(int x);
int main()
{
    int x;
    cout << "Enter a number: ";
    cin >> x;
    int sum = sumOfdigit(x);
    cout << "Sum of digit: " << sum << endl;
}
int sumOfdigit(int x)
{
    int sum = 0;
    while (x != 0)
    {
        sum += (x % 10);
        x = x / 10;
    }
    return sum;
}