#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10

int main()
{
    int n, q;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int order, start, finish;
        cin >> order >> start >> finish;
        if (order == 0)     // 範囲内の最小値
        {
            cout << *min_element(a.begin() + start, a.begin() + finish) << endl;
        }
        if (order == 1)     // 範囲内の最大値
        {
            cout << *max_element(a.begin() + start, a.begin() + finish) << endl;
        }
    }
    return 0;
}