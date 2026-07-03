#include <iostream>
using namespace std;
void menu();
void menu1();
int convertIntoBinary();
int sumOfdigit();
void primeNumber();
int factorial(int n);
int nCr();
void pyramidPattern();
void invertedPramid();
void trianglePattern();
void invertedTriangle();
void convertIntoDecimal();
int main()
{
    menu();
    int choise;
    cin >> choise;
    while (choise != 0)
    {
        // Sum of digit of a number ;
        if (choise == 1)
        {
            int sum = sumOfdigit();
            cout << "Sum of digit: " << sum << endl;
        }

        // Prime number;
        if (choise == 2)
        {
            primeNumber();
        }

        // Find nCr;
        if (choise == 3)
        {
            int ncr = nCr();
            cout << "nCr: " << ncr << endl;
        }

        // Decimal to binary
        else if (choise == 4)
        {
            int result = convertIntoBinary();
            cout << "Binary Number: " << result << endl;
        }

        // Binary to decimal;
        if (choise == 5)
        {
            convertIntoDecimal();
        }

        // Pattern menu;
        else if (choise == 6)
        {
            menu1();
            int choise1;
            cin >> choise1;
            while (choise1 != 0)
            {
                // Pyramid Pattern;
                if (choise1 == 1)
                {
                    pyramidPattern();
                }

                // Inverted Pyramid Pattern;
                else if (choise1 == 2)
                {
                    invertedPramid();
                }

                // Triangle Pattern;
                else if (choise1 == 3)
                {
                    trianglePattern();
                }

                // Inverted Triangle Pattern;
                else if (choise1 == 4)
                {
                    invertedTriangle();
                }

                // Next menu;
                else if (choise1 == 5)
                {
                    cout << "5. Next.";
                }

                // Previous menu;
                else if (choise1 == 6)
                {
                    break;
                }

                menu1();
                cin >> choise1;
            }

            // exit;
            if (choise1 == 0)
            {
                return 0;
            }
        }
        menu();
        cin >> choise;
    }
}

// Main Menu;
void menu()
{
    cout << endl;
    cout << "------***------" << endl;
    cout << endl;
    cout << "1. Sum of digit of a number." << endl;
    cout << "2. Prime number." << endl;
    cout << "3. Find nCr." << endl;
    cout << "4. Decimal to binary." << endl;
    cout << "5. Binary to decimal." << endl;
    cout << "6. Next(Pattern)." << endl;
    cout << "0. Exit." << endl;
    cout << endl;
    cout << "------***------" << endl;
    cout << endl;
    cout << "Enter your choise: ";
}

// Menu1;
void menu1()
{
    cout << endl;
    cout << "------***------" << endl;
    cout << endl;
    cout << "1. Pyramid Pattern." << endl;
    cout << "2. Inverted Pyramid Pattern." << endl;
    cout << "3. Triangle Pattern." << endl;
    cout << "4. Inverted Triangle Pattern." << endl;
    cout << "5. Next." << endl;
    cout << "6 previous." << endl;
    cout << "0. Exit." << endl;
    cout << endl;
    cout << "------***------" << endl;
    cout << endl;
    cout << "Enter your choise: ";
}

// Decimal to binary;
int convertIntoBinary()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
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

// Sum of digit of a number;
int sumOfdigit()
{
    int x;
    cout << "Enter a number: ";
    cin >> x;
    int sum = 0;
    while (x != 0)
    {
        sum += (x % 10);
        x = x / 10;
    }
    return sum;
}

// Prime Number
void primeNumber()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    bool isPrime = true;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            isPrime = false;
            break;
        }
    }
    if (!isPrime)
    {
        cout << n << " Not a prime number\n";
    }
    else
    {
        cout << n << " Prime number\n";
    }
}

// Factorial;
int factorial(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

// nCr;
int nCr()
{
    int n, r;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the value of r:";
    cin >> r;
    int fact_n = factorial(n);
    int fact_r = factorial(r);
    int fact_NminousR = factorial(n - r);
    return fact_n / (fact_r * fact_NminousR);
}

// Pyramid Pattern
void pyramidPattern()
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

// Inverted Pyramid Pattern
void invertedPramid()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++) // space
        {
            cout << " ";
        }
        for (int j = i, k = 1; j < n; k++, j++) // 1st triangle
        {
            cout << k;
        }
        for (int j = n - i - 1; j > 0; j--) // 2nd triangle
        {
            cout << j;
        }
        cout << endl; // space,1st triangle,2nd triangle this three loop print in same line and than print the next line ;
    }
}

// Triangle Pattern
void trianglePattern()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

// Inverted Triangle Pattern
void invertedTriangle()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < n - i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

// Binary to Decimal;
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