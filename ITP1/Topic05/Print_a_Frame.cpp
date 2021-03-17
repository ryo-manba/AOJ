#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    while (1)
    {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0) return 0;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if (j == b - 1)
                {
                    cout << '#' << endl;
                }
                else if (i == 0 || i == a - 1 || j == 0)
                    cout << '#';
                else
                    cout << '.';
            }
        }
        cout << endl;
    }
    return 0;
}