#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10

int main()
{
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) cin >> b[i];

    int mini = min(m, n);
    for (int i = 0; i < mini; i++)
    {
        if (a[i] < b[i])
        {
            cout << 1 << endl;
            return 0;
        }
        if (a[i] > b[i])
        {
            cout << 0 << endl;
            return 0;
        }
    }
    if (mini == n && m != n)
        cout << 1 << endl;
    else
        cout << 0 << endl;
    return 0;
}