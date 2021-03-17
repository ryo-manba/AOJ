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
        for (int i = 1; i <= a; i++) {
            for (int j = 1; j <= b; j++) {
                if ((i + j) % 2 == 0)
                {
                    cout << '#';
                    if (j == b) cout << endl;
                }
                else
                {
                    cout << '.';
                    if (j == b) cout << endl;
                }
            }
        }
        cout << endl;
    }
    return 0;
}