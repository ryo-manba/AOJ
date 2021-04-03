#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int bfs(vector<vector<int>> p)
{
    vector<vector<int>> goal = { {1, 2, 3},
                                 {4, 5, 6},
                                 {7, 8, 0} };
    map<vector<vector<int>>,int> D;
    queue<pair<vector<vector<int>>,int>> que;

    D[p] = 1;
    que.push(make_pair(p, 1));

    // search
    if (p == goal)  return 0;

    while (!que.empty())
    {
        pair<vector<vector<int>>,int> p1 = que.front();
        que.pop();

        int tx = -1, ty = -1;

        for (int i = 0; i < p1.first.size(); i++)
        {
            for (int j = 0; j < p1.first[i].size(); j++)
            {
                if (p1.first[i][j] == 0)
                {
                    tx = j;
                    ty = i;
                }
            }
        }

        // moving
        for (int dir = 0; dir < 4; dir++)
        {
            if (0 <= tx + dx[dir] && tx + dx[dir] < p1.first[0].size() && 0 <= ty + dy[dir] && ty + dy[dir] < p1.first.size())
            {
                vector<vector<int>> p2 = p1.first;

                swap(p2[ty][tx], p2[ty + dy[dir]][tx + dx[dir]]);
                if (D[p2] == 0)
                {
                    if (p2 == goal)
                        return p1.second;
                    D[p2] = p1.second + 1;
                    que.push(make_pair(p2, p1.second + 1));
                }
            }
        }
    }
    return -1;
}

int main()
{
    vector<vector<int>> board(3, vector<int>(3, -1));;

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            cin >> board[i][j];
        }
    }

    cout << bfs(board) << endl;
    return 0;
}