#include <iostream>
using namespace std;
void convertIntoDecimal()
{
    int n;
    cout << "Enter a Binary Number: ";
    cin >> n;
    int pow = 1;
    int ans = 0;
    while (n != 0)
    {
        int rem = n % 10;
        ans += rem * pow;
        n = n / 10;
        pow *= 2;
    }
    cout << "Decimal Number: " << ans << endl;
}
int main()
{
    convertIntoDecimal();
}