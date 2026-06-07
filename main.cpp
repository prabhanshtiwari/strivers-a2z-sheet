#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector <int> v = {1, 2, 3, 4, 5};

    for (auto it : v)
    {
        cout << it << " "; // 'it' takes each value directly (not an iterator/address)
    }

    auto x = 10;
    auto y = 3.14;

    cout << typeid(x).name() << endl;
    cout << typeid(y).name() << endl;

    return 0;
}