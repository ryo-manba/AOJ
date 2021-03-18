#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 4000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;

// 最大公約数

int main()
{
    int x, y, r;
    cin >> x >> y;
    if (x < y)  swap(x, y);
    if (x >= y)
    {
        while (y > 0)
        {
            r = x % y;
            x = y;
            y = r;
        }
    }
    cout << x << endl;
    return 0;
}