#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main()
{
    int n, m;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        ll k;
        cin >> k;
        if (!binary_search(a.begin(), a.end(), k))
        {
            cout << 0 << endl;
            return 0;
        }
    }
    cout << 1 << endl;
    return 0;
}