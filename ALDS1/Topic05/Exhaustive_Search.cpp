#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7;
#define EPS = 1e-10;

// 再帰関数を用いた全列挙

int n;
vector<int> a(20);

// i番目の要素を使ってbが作れるか
bool solve(int i, int b)
{
    if (b == 0)
        return true;
    // iが要素数より大きい場合 or bが0未満の場合
    else if (i >= n || b < 0)
        return false;
    else
        // 全てのパターンを試す (b - a[i]で選択した場合)
        return solve(i + 1, b) || solve(i + 1, b - a[i]);
}

int main()
{
    int q;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> q;
    vector<string> ans(q);

    for (int i = 0; i < q; i++)
    {
        int b;
        cin >> b;
        if (solve(0, b))
            ans[i] = "yes";
        else
            ans[i] = "no";
    }
    
    for (int i = 0; i < q; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}