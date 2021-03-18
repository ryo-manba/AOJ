#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7;
#define EPS = 1e-10;

// バブルソート (泡（Bubble）が水面に上がっていくように配列の要素を動かす)

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int cnt = 0;
    bool flag = true;
    while (flag)
    {
        flag = false;
        for (int i = n - 1; i > 0; i--)
        {
            if (a[i] < a[i - 1])
            {
                swap(a[i], a[i - 1]);
                flag = true;
                cnt++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i];
        if (i == n - 1) cout << endl;
        else    cout << " ";
    }
    cout << cnt << endl;

    return 0;
}