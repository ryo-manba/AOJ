#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

//  最小公倍数

ll gcd(ll x, ll y)
{
    ll r;
    while((r = x % y) != 0)
    {
        x = y;
        y = r;
    }
    return y;
}

ll lcm(ll x, ll y)
{
    return (x * y / gcd(x,y));
}

int main()
{
    int n;
    cin >> n;
    ll ans = 1;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        ans = lcm(ans, a);
    }
    cout << ans << endl;
    return 0;
}