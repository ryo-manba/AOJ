#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

#define N 8

int main()
{
    int k, i, j;
    cin >> k;
    vector<string> board(N, "........"); // boardを初期化
    int r, c;
    for (i = 0; i < k; i++)
    {
        cin >> r >> c;
        board[r][c] = 'Q';
    }
    vector<int> a(N);
    for (i = 0; i < N; i++) a[i] = i;

    do{
        bool ok = true;
        //被らない順列の生成
        for (i = 0; i < N; i++) {
            for (j = 0; j < i; j++) {
                // 斜めの確認
                if (abs(i - j) == abs(a[i] - a[j])) ok = false;                
            }
        }
        if (!ok) continue;

        //最初に設置したqueenをcheckする
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                if (board[i][j] == 'Q' && a[i] != j) ok = false;
            }
        }
        if (!ok) continue;
        
        //a[i]にqueenを設置
        for (i = 0; i < N; i++) board[i][a[i]] = 'Q';
        for (i = 0; i < N; i++) cout << board[i] << endl;
        return 0;
    } while(next_permutation(a.begin(), a.end()));
    return 0;
}