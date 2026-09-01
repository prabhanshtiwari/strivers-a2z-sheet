#include<bits/stdc++.h>
using namespace std;

void pattern1(int n){
    cout << "Pattern 1 - Solid Rectangle of Stars" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
           cout << "*" << " ";
        }
        cout << endl;
    }
    
}

void pattern2(int n){

    cout << "Pattern 2 - Right-Angled Triangle (Stars, Increasing)" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
           cout << "*" << " ";
        }
        cout << endl;
    }

}

void pattern3(int n){

    cout << "Pattern 3 - Right-Angled Triangle (Numbers 1 to Row Number)" << endl;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
           cout << j << " ";
        }
        cout << endl;
    }

}

void pattern4(int n){

    cout << "Pattern 3 - Right-Angled Triangle (Row Number Repeated)" << endl;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
           cout << i << " ";
        }
        cout << endl;
    }

}

void pattern5(int n) {

    cout << "Pattern 5 — Inverted Right-Angled Triangle (Stars, Decreasing)" << endl;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << "*" << " ";
        }
        cout << endl;
    }
    
}

void pattern6(int n) {

    cout << "Pattern 6 — Inverted Right-Angled Triangle (Numbers, Decreasing)" << endl;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    
}

int main(){

    int N;
    cout << "Enter a number: ";
    cin >> N;

    pattern6(N);


    return 0;
}