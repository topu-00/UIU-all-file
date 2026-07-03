#include <iostream>
using namespace std;
int powerOfTwo();
int main()
{
    int flag = powerOfTwo();
    if (flag == 1)
    {
        cout << "Power of two!" << endl;
    }
    else
    {
        cout << "Not Power Of two!" << endl;
    }
}
int powerOfTwo()
{
    int n;
    cout << "Entre a value: ";
    cin >> n;
    int x = 1;
    while (1)
    {
        if (x == n)
        {
            return 1;
        }
        else if (x > n)
        {
            break;
        }
        else
        {
            x = x << 1;
        }
    }
    return -1;
}