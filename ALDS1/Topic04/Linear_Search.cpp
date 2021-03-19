#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7;
#define EPS = 1e-10;

/* 線形探索 (配列の先頭から各要素が目的の値と等しいかどうかを順番に調べる。
            等しいものが見つかった時点でその位置を返し探索を終了する。)*/

int main()
{
    int n, q, cnt = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> q;
    vector<int> b(q);
    for (int i = 0; i < q; i++) cin >> b[i];

    for (int i = 0; i < q; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (b[i] == a[j]) 
            {
                cnt++;
                j = n;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}