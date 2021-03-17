#include<iostream>
using namespace std;

int main()
{
    for (int i = 1; i <= 10000; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0) return 0;
        if (a > b) swap(a, b);
        cout << a << " " << b << endl;
    }
    return 0;
}