#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 4000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;

int main()
{
    while (1)
    {
        int m, f, r;
        char ans;
        cin >> m >> f >> r;
        if (m > 50) m = 50;
        if (f > 50) f = 50;
        if (r > 100) r = 100;

        if (m + f >= 80) ans = 'A';
        if (m + f >= 65 && m + f < 80) ans = 'B';
        if (m + f >= 50 && m + f < 65) ans = 'C';
        if (m + f >= 30 && m + f < 50 && r >= 50) ans = 'C';
        if (m + f >= 30 && m + f < 50 && r < 50) ans = 'D';
        if (m + f < 30) ans = 'F';
        if (m == -1 && f != -1) ans = 'F';
        if (m != -1 && f == -1) ans = 'F';
        if (m == -1 && f == -1 && r == -1) return 0;
        cout << ans << endl;
    }
    return 0;
}