#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    while (1)
    {
        int a, b;
        char c;
        cin >> a >> c >> b;
        if (c == '+') cout << a + b << endl;
        if (c == '-') cout << a - b << endl;
        if (c == '*') cout << a * b << endl;
        if (c == '/') cout << a / b << endl;
        if (c == '?') return 0;
    }
    return 0;
}