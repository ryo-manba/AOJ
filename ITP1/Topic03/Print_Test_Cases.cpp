#include<iostream>
using namespace std;

int main()
{
    for (int i = 1; i <= 10000; i++)
    {
        int x;
        cin >> x;
        if (x == 0) return 0;
        cout << "Case " << i << ": " << x << endl;
    }
    return 0;
}