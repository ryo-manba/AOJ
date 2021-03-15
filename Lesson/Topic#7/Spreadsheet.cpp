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
    int r, c;
    cin >> r >> c;
    int a[r + 1][c + 1];
    for (int i = 0; i < r; i++) {
        int ans = 0;
        for (int j = 0; j < c; j++)
        {
            cin >> a[i][j];
            ans += a[i][j];
            if (j == c - 1)
            {
                a[i][c] = ans;
            }
        }
    }

    for (int i = 0; i < c ; i++) {
        int ans = 0;
        for (int j = 0; j < r; j++) {
            ans += a[j][i];
            if (j == r - 1)
            {
                a[r][i] = ans;
            }                   
        }
    }

    int ans = 0;
    for (int i = 0; i < c; i++)
    {
        ans += a[r][i];
    }
    a[r][c] = ans;

    for (int i = 0; i <= r; i++) {
        for (int j = 0; j <= c; j++) {
            cout << a[i][j];
            if (j == c) cout << endl;
            else cout << " ";
        }
    }
    return 0;
}
