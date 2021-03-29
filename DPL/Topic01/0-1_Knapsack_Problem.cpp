#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10

int N, W;
int value[110], weight[110];
int dp[110][110110] = {0};

int main()
{
    cin >> N >> W;
    for (int i = 0; i < N; i++)
        cin >> value[i] >> weight[i];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (j - weight[i] >= 0)  // 重さの合計が範囲を超えてしまう場合はbreak
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - weight[i]] + value[i]);
                
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]); // i 番目の品物を選ばない場合
        }
    }
    cout << dp[N][W] << endl;
    return 0;
}