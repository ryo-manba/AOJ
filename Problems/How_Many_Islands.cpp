#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int h, w;
vector<vector<int>> mp;

void dfs(int x, int y)
{
    mp[x][y] = 0;
    for (int i = 0; i < 8; i++)
    {
       int nx = x + dx[i];
       int ny = y + dy[i];
       if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
       if (mp[nx][ny] == 0) continue;
        dfs(nx, ny);
    }
}

int main()
{
    while(cin >> w >> h)
    {
        if (w == 0 || h == 0) break;
        mp.assign(h, vector<int>(w, 0));

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> mp[i][j];
            }
        }
        
        int cnt = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (mp[i][j] == 0) continue;        
                dfs(i, j);
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}