#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10

/*  連結成分分解
    連結
    - 無向グラフにおいて、すべての頂点間で互いに行き来できる
    強連結
    - 有向グラフにおいて、すべての頂点間で互いに行き来できる
*/

using Graph = vector<vector<int>>;

int main()
{
    // 頂点数と辺数
    int n, m;
    cin >> n >> m;

    // 無向グラフ
    Graph G(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<bool> seen(n, false);
    stack<int> sta;
    vector<int> match(n, 0);
    // 連結している場合は同じid
    int id = 0;
    for (int i = 0; i < n; i++) {    
        if (seen[i] == false)
        {
            id++;
            seen[i] = true;
            sta.push(i);
            match[i] = id;
            while (!sta.empty())
            {
                int v = sta.top();
                sta.pop();
                for (int next : G[v])
                {
                    if (!seen[next])
                    {
                        seen[next] = true;
                        match[next] = id;
                        sta.push(next);
                    }
                }
            }
        }
    }

    // 質問を受け取る
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        // s からt にたどり着けるか
        int s, t;
        cin >> s >> t;

        // idで確かめることで O(1)で調べられる
        if (match[s] == match[t])
            cout << "yes" << endl;
        else 
            cout << "no" << endl;
        }
    return 0;
}