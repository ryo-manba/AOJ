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
        ll start, finish, find_num;
        cin >> start >> finish >> find_num;
        cout << count(a.begin() + start, a.begin() + finish, find_num) << endl;
    }
    return 0;   
}