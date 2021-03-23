#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10

/*  幅優先探索 (BFS)
    1. 始めの状態から遷移可能な状態を、全てキューに入れる
    2. キューに要素がなければ終了する
    3. 現在の状態から遷移可能な状態を、全てキューに入れる
    4. キューから1つ要素を取り出し、そこに状態を遷移させる
    5. 2.に戻る
*/

#define Graph vector<vector<int> >

int main()
{
    int n;
    cin >> n;
    
    // 有向グラフの入力
    Graph G(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        for (int j = 0; j < b; j++)
        {
            int c;
            cin >> c;
            c--;
            // 計算しやすいように0-indexed にする
            G[a].push_back(c);
        }
    }

    // BFS のためのデータ構造
    vector<int> dist(n, -1);
    queue<int> que;

    // 初期条件 (頂点 0 を初期ノードとする)
    dist[0] = 0;
    que.push(0);
    // キューが空になるまで
    while (!que.empty())
    {
        int v = que.front();
        que.pop();

        // v から辿れる頂点をすべて調べる
        for (auto nv : G[v]) 
        {
            if (dist[nv] != -1) continue;

            // 新たな頂点に対して距離情報を更新してキューに追加する
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }

    for (int i = 0; i < n; i++) 
    {
        cout << i + 1 << " " << dist[i] << endl;
    }
    return 0;
}