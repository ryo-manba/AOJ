#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10

/*  深さ優先探索 (DFS)
    とりあえずこれ以上進めなくなるまで探索したら、戻って別のルートで探索し直す
    1. 現在探索中の頂点 u を「探索済み」として記録しておく
    2. u と隣接している頂点のうち、「未探索」の頂点 v について以下を行う
        1. dfs(v) によって v を探索する
*/

#define Graph vector<vector<int> >

vector<bool> seen;
vector<int> first;    // 行き
vector<int> last;     // 帰り

// timeを参照渡ししないと時間がリセットされる
void dfs(const Graph &G, int v, int &time) 
{
    // 行きがけ順をインクリメントしながらメモ
    first[v] = time++;

    seen[v] = true;
    for (auto next : G[v]) // vから行ける next をすべて調べる
    {
        if (seen[next]) continue;
        dfs(G, next, time); // 再帰的に探索
    }    
    // 帰りがけ順をインクリメントしながらメモ
    last[v] = time++;
}

int main()
{
    int n;
    cin >> n;
    Graph G(n + 1);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        for (int j = 0; j < b; j++)
        {
            int c;
            cin >> c;
            G[a].push_back(c);
        }
    }    

    seen.assign(n + 1, false);  //全頂点を未訪問に初期化
    first.resize(n + 1);
    last.resize(n + 1);
    int time = 1;

    // グラフがつながっていない場合も考慮
    for (int i = 1; i <= n; i++)
    {
        if (seen[i]) continue;
        else    dfs(G,i, time);
    }

    for(int i = 1; i <= n; i++)
    {
        cout << i << " " << first[i] << " " << last[i] << endl; 
    }
    return 0;
}