#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

// 部分集合の部分集合の列挙

int main()
{
    int n, k, t = 0;
    cin >> n >> k;
    for (int i = 0; i < k; i++) 
    {
        int b;
        cin >> b;
        t |= (1 << b);  // t は部分集合、 b がその要素
    }
    for (int i = 0; i < (1 << n); i++)
    {
        if (i & ~t) continue;
        cout << i << ":";
        for (int j = 0; j < n; j++)
        {
            if (i >> j & 1)
                cout << " " << j;
        }
        cout << endl;
    }
    return 0;
}