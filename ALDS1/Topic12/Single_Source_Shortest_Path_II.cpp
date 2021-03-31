#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

/*  単一始点最短経路
    始点を固定した時に、他のすべての頂点への最短経路を求める問題のこと。
    
    ダイクストラ法：
    1. 始点 s を「既に最短距離が確定した頂点」、他の頂点を「まだ最短距離が確定していない頂点」とする
    2. 以下をすべての頂点の最短距離が確定するまで繰り返す
    3. 全ての「既に最短距離が確定した頂点 u 」から「まだ最短距離が確定していない頂点 v 」へ伸びる全ての辺 e=(u,v) について、「v と d[v] の候補」をまとめておく
    4. 候補の中から、d[v] が最小のものを選択し、v を「既に最短距離が確定した頂点」に加える

    ヒープを使わない場合：𝑂(|V|^2)
    ヒープを使う時：　𝑂(|E|log|V|)
    priority_queue をヒープとして利用することができる。
*/

int main()
{
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> G(n);

    for (int i = 0; i < n; i++)
    {
        int u, k;
        cin >> u >> k;
        while (k--)
        {
            int v, c;
            cin >> v >> c;
            G[u].emplace_back(v, c);
        }
    }

    vector<ll> d(n, INFL);
    using P = pair<ll, int>;
    priority_queue<P, vector<P>, greater<P>> pq;    // greater で距離が小さい順に取り出せる
    d[0] = 0;       // 始点s への最短距離は0
    pq.emplace(d[0], 0);
    while (!pq.empty())
    {
        auto [now, u] = pq.top();
        pq.pop();
        if (d[u] < now) continue;   // 最短距離でなければ無視
        for (auto [v, weight] : G[u])
        {
            if (d[v] > now + weight)    // 最短距離候補ならpq に追加
            {
                d[v] = now + weight;
                pq.emplace(d[v], v);
            }
        }
    }

    for (int u = 0; u < n; u++)
        cout << u << " " << d[u] << endl;
}