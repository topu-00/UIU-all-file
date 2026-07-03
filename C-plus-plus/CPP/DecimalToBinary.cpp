#include <iostream>
using namespace std;
int convertIntoBinary(int n);
int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Binary Number: " << convertIntoBinary(n) << endl;
}

int convertIntoBinary(int n)
{
    int power = 1;
    int sum = 0;
    while (n > 0)
    {
        int x = n % 2;
        n /= 2;
        sum += (x * power);
        power *= 10;
    }
    return sum;
}