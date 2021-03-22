#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10

/*  有向グラフの隣接行列
    行列の 行，列 頂点集合 に対応
    頂点 u から v に向かう枝が
    存在している (u, v)の要素＝１
    存在していない (u, v)の要素＝0
*/

int main()
{
    int n;
    cin >> n;
    int G[100][100] = {{0}};

    for (int i = 0; i < n; i++) 
    {
        // ver 頂点数, edges 出次数
        int ver, edges;
        cin >> ver >> edges;
        ver--;
        for (int j = 0; j < edges; j++)
        {
            int a[edges];
            cin >> a[j];
            a[j]--;
            G[ver][a[j]]++;
        }
    }

    // 有向グラフの隣接行列を出力
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << G[i][j];
            if (j == n - 1) cout << endl;
            else    cout << " ";
        }
    }
    return 0;
}