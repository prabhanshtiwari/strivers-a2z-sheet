#include <bits/stdc++.h>
using namespace std;

void printPattern1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void printPattern2(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void printPattern3(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << j + 1 << " ";
        }
        cout << endl;
    }
}

void printPattern4(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << i + 1 << " ";
        }
        cout << endl;
    }
}

void printPattern5(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void printPattern6(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void printPattern7(int n)
{
    for (int i = 0; i < n; i++)
    {

        // spaces
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }

        // starts
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void printPattern8(int n)
{
    for (int i = 0; i < n; i++)
    {

        // spaces
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        // stars
        for (int j = 0; j < 2 * n - 2 * i - 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void printPattern9(int n)
{
    for (int i = 0; i < n; i++)
    {

        // spaces
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }

        // starts
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {

        // spaces
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        // stars
        for (int j = 0; j < 2 * n - 2 * i - 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void printPattern10(int n)
{
    for (int i = 1; i < 2 * n - 1; i++)
    {
        int stars;
        if (i <= n)
        {
            stars = i;
        }
        else
        {
            stars = 2 * n - i;
        }
        // Print the stars
        for (int j = 0; j < stars; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void printPattern11(int n)
{
    for (int i = 0; i < n; i++)
    {
        int num;
        {
            i % 2 == 0 ? num = 1 : num = 0;
        }
        for (int j = 0; j <= i; j++)
        {
            cout << num << " ";
            num = !num;
        }
        cout << endl;
    }
}

void printPattern12(int n)
{
    for (int i = 1; i <= n; i++)
    {
        // numbers
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        // spaces
        for (int j = 1; j <= 2 * n - 2 * i; j++)
        {
            cout << " ";
        }
        // numbers
        for (int j = i; j >= 1; j--)
        {
            cout << j;
        }

        cout << endl;
    }
}

void printPattern13(int n)
{
    int num = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << num++ << " ";
        }
        cout << endl;
    }
}

void printPattern14(int n)
{

    for (int i = 1; i <= n; i++)
    {
        char ch = 'A';
        for (int j = 1; j <= i; j++)
        {
            cout << ch++;
        }
        cout << endl;
    }
}

void printPattern15(int n)
{
    for (int i = 0; i < n; i++)
    {
        char ch = 'A';

        for (int j = 0; j < n - i; j++)
        {
            cout << ch;
            ch++;
        }

        cout << endl;
    }
}

void printPattern16(int n)
{
    char ch = 'A';
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j <= i; j++)
        {
            cout << ch;
        }
        cout << endl;
        ch = ch + 1;
    }
}

void printPattern17(int n)
{
    for (int i = 0; i < n; i++)
    {
        // spaces
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        // characters
        char ch = 'A';
        // int breakpoint = (2 * i + 1) / 2;
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << ch;

            if (j < i)
                ch++; // Left half including peak
            else
                ch--; // Right half
        }
        cout << endl;
    }
}

void printPattern18(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char ch = ('A' + n - 1) - i; ch <= ('A' + n - 1); ch++)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
}

void printPattern19(int n)
{
    // upper half
    for (int i = 0; i < n; i++)
    {
        // stars
        for (int j = 0; j < n - i; j++)
        {
            cout << "*";
        }

        // spaces
        for (int j = 0; j < 2 * i; j++)
        {
            cout << " ";
        }

        // stars
        for (int j = 0; j < n - i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    // lower half
    for (int i = 0; i < n; i++)
    {
        // stars
        for (int j = 0; j < i + 1; j++)
        {
            cout << "*";
        }

        // spaces
        for (int j = 0; j < 2 * (n - i - 1); j++)
        {
            cout << " ";
        }

        // stars
        for (int j = 0; j < i + 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void printPattern20(int n)
{
    for (int i = 0; i < 2 * n - 1; i++)
    {
        // stars
        if (i < n)
        {
            for (int j = 0; j < i + 1; j++)
            {
                cout << "*";
            }
        }
        else
        {
            for (int j = 0; j < 2 * n - 1 - i; j++)
            {
                cout << "*";
            }
        }

        // spaces
        if (i < n)
        {
            for (int j = 0; j < (2 * n - 1) - (2 * i) - 1; j++)
            {
                cout << " ";
            }
        }
        else
        {
            for (int j = 0; j < (2 * i) - (2 * n - 1) + 1; j++)
            {
                cout << " ";
            }
        }

        // stars
        if (i < n)
        {
            for (int j = 0; j < i + 1; j++)
            {
                cout << "*";
            }
        }
        else
        {
            for (int j = 0; j < 2 * n - 1 - i; j++)
            {
                cout << "*";
            }
        }
        cout << endl;
    }
}

void printPattern21(int n){
    for(int i = 0; i < n; i++) {
        
    }
}

int main()
{
    int n;
    cout << "Input a number now..." << endl;
    cin >> n;
    cout << "Pattern printing below:\n";

    // printPattern1(n);
    // printPattern2(n);
    // printPattern3(n);
    // printPattern4(n);
    // printPattern5(n);
    // printPattern6(n);
    // printPattern7(n);
    // printPattern8(n);
    // printPattern9(n);
    // printPattern10(n);
    // printPattern11(n);
    // printPattern12(n);
    // printPattern13(n);
    // printPattern14(n);
    // printPattern15(n);
    // printPattern16(n);
    // printPattern17(n);
    // printPattern18(n);
    // printPattern19(n);
    // printPattern20(n);
    printPattern21(n);

    return 0;
}