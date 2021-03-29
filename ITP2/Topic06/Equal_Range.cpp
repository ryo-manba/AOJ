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
    int n, q;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int k;
        cin >> k;
        decltype(a)::iterator low = lower_bound(a.begin(), a.end(), k);
        decltype(a)::iterator up = upper_bound(a.begin(), a.end(), k);
        int low_pos = distance(a.begin(), low);
        int up_pos = distance(a.begin(), up);
        cout << low_pos << " " << up_pos << endl;
    }
    // cout << (lower_bound(a.begin(), a.end(), k) - a.begin())
    // a.begin() を引くだけでも出力出来る
    return 0;
}