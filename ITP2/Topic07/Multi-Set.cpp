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
    int q;
    cin >> q;
    multiset<ll> st;
    for (int i = 0; i < q; i++)
    {
        ll order, n;
        cin >> order >> n;
        if (order == 0)     // 要素を挿入
        {
            st.insert(n);
            cout << st.size() << endl;
        }
        if (order == 1)     // n の数を出力
        {
            cout << st.count(n) << endl;
        }
        if (order == 2)     // 要素の削除
        {
            st.erase(n);
        }
        if (order == 3)     // n <= a の範囲の要素を出力
        {
            ll a;
            cin >> a;
            decltype(st)::iterator it = st.lower_bound(n);
            decltype(st)::iterator last = st.upper_bound(a);
            while (it != last)
            {
                cout << *it << endl;
                it++;
            }
        }
    }
    return 0;
}