#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

/*  拡張ユークリッドの互除法
    1. b が 0 ならば、x を 1, y を 0 にして、a を返す
    2. b が 0 でなければ、
        1. extend_gcd(b, a%b, y, x) を呼び出して結果をdとする
        2. y から a/b*x を引く
        3. dを返す
*/

// 返り値: a と b の最大公約数
// ax + by = gcd(a, b) を満たす (x, y) が格納される
ll extend_gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) 
    {
        x = 1;
        y = 0;
        return a;
    } 
    else 
    {
        ll d = extend_gcd(b, a % b, y, x);
        y -= a / b * x;
        return d;
    }
}

int main()
{
    ll a, b, x, y;
    cin >> a >> b;
    extend_gcd(a, b, x, y);
    cout << x << " " << y << endl;
    return 0;
}