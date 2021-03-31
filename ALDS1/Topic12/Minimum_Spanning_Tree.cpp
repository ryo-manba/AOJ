#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

/*  最小全域木 (minimum spanning tree)
    重みの総和が最小になるように辺を選んで作った全域木のこと。
    グラフが隣接リストで与えられる時はクラスカル法で、
    隣接行列で与えられる時はプリム法を用いたほうが実装しやすい。
*/

vector<vector<int>> G;

struct Prim     // プリム法で最小全域木を求める構造体
{
    int sum;                // 重みの総和
    int n;                  // 頂点数
    vector<int> mincost;    // 既に確定した頂点から最小のコスト
    vector<bool> used;      // 既に確定しているかどうか
    Prim(vector<vector<int>> const& Graph) 
    {
        init(Graph);
    }

    void init(vector<vector<int>> const& Graph)
    {
        n = (int)Graph.size();
        mincost.assign(n, INF);
        used.assign(n, false);
        sum = 0;
        mincost[0] = 0;     // 頂点0からスタート
        while (true)
        {
            int v = -1;
            for (int u = 0; u < n; u++)     // コストが最小で行ける頂点 v を探す
            {
                if (!used[u] && (v == -1 || mincost[u] < mincost[v]))
                    v = u;
            }
            if (v == -1) break; // MST が出来たので終了
            used[v] = true;
            sum += mincost[v];
            for (int u = 0; u < n; u++)     //確定した頂点から行ける頂点について、最小コストを更新
            {
                if (Graph[v][u] != -1)
                    mincost[u] = min(mincost[u], Graph[v][u]);
            }
        }
    }
};

int main()
{
    int n;
    cin >> n;
    G.assign(n, vector<int> (n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> G[i][j];
        }
    }
    Prim prim(G);
    cout << prim.sum << endl;
}