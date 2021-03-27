#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10

int main()
{
    ll n, a, b;
    cin >> n >> a >> b;
    ll tmp = n * a;
    string ans = to_string(tmp);
    for (int i = 0; i < b; i++)
        ans += '0';
    cout << ans << endl;
    return 0;
}