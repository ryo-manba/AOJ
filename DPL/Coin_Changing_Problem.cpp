#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10

/*  コイン問題
    n 種類のコインを使ってちょうど cost 円を支払う時の最小の枚数を求める。
*/

int main()
{
    int cost, n;
    cin >> cost >> n;
    vector<int> coin(n);
    vector<int> dp(50010, INF);         // 大きい値で初期化
    for (int i = 0; i < n; i++) 
        cin >> coin[i];
    sort(coin.begin(), coin.end());

    dp[0] = 0;
    for (int i = 0; i < cost; i++)      // 必ず 1 を含むからcost の値は超えない
    {
        for (int j = 0; j < n; j++)
        {
            if (i + coin[j] > cost) break;      // コストを越えたらbreak
            dp[i + coin[j]] = min(dp[i + coin[j]], dp[i] + 1);
        }
    }
    cout << dp[cost] << endl;
    return 0;
}