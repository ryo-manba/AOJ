#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

/*  オイラーのφ関数(トーシェント関数)
    自然数 n と互いに素な n 以下の自然数の個数が求められる
    m, n を互いに素な自然数とすると、φ(mn) = φ(m)φ(n) が成り立つ
    ex) φ(36) = φ(2^2 * 3^2) = φ(2^2)φ(3^2) = (2^2 - 2)(3^2 - 3) = 12
*/

vector<pair<int, int>> p;

void prime(ll n)
{
    for (int i = 2; n > 1; i += 2)
    {
        if (i == 4) i--;
        if (n % i == 0)
        {
            int j = 0;
            while (n % i == 0)
            {
                n /= i;
                j++;
            }
            p.push_back(make_pair(i, j));
        }
    }
}

int main()
{
    int n;
    cin >> n;
    prime(n);
    ll ans = 1;
    for (auto a : p)
    {
        ans *= (pow(a.first, a.second) - pow(a.first, a.second - 1));
    }
    cout << ans << endl;
    return 0;
}