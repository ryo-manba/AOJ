#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    decltype(a)::iterator result = unique(a.begin(), a.end());
    a.erase(result, a.end());
    int i = 0;
    for (auto v : a)
    {
        if (i++) cout << " ";
        cout << v;
    }
    cout << endl;
    return 0;
}