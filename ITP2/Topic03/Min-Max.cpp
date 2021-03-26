#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10

int main()
{
    ll a, b, c;
    cin >> a >> b >> c;
    ll mini = min({a, b, c});
    ll maxi = max({a, b, c});
    cout << mini << " " << maxi << endl;
    return 0;
}