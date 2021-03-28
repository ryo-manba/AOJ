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
    vector<int> num(n);
    for (int i = 0; i < n; i++)
        cin >> num[i];
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        rotate(num.begin() + a, num.begin() + b, num.begin() + c);
    }

    for (int i = 0; i < n; i++)
    {
        if (i) cout << " ";
        cout << num[i];
    }
    cout << endl;
    return 0;
}