#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

//  高速なべき乗(計算量 Ologn)

// a^n mod を計算する
ll modpow(ll a, ll n, ll mod)
{
    ll res = 1;
    while (n > 0)
    {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
int main()
{
    ll m, n;
    cin >> m >> n;
    cout << modpow(m, n, MOD) << endl;
    return 0;
}