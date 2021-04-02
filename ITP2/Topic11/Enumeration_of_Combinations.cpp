#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

// n この整数から異なるk 個の整数を選ぶ組み合わせの列挙

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < (1 << n); i++)
    {
        if (__builtin_popcount(i) - k) continue;    // 立っているビットを数える(k 個だったら0 で抜ける)
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