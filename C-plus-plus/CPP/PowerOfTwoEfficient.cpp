#include <iostream>
using namespace std;
bool powerOfTwo(int n)
{
    return n > 0 && (n & (n - 1)) == 0;
}
int main()
{
    int n;
    cout << "Enter a positive number: ";
    cin >> n;
    if (powerOfTwo(n))
    {
        cout << "Power of two!" << endl;
    }
    else
    {
        cout << "Not power of two!" << endl;
    }
    return 0;
}