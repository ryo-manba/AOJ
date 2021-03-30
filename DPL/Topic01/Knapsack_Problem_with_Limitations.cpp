#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

/*  個数制限付きナップサック問題
    各品物について、品物を 1 個入れたとき、2 個入れたとき・・・と愚直に 
    1 ずつ増やして考えていくと計算量的に間に合わない。
    そこで、繰り返し二乗法のように、取る数を 2 倍ずつ増やしていくことで考える。

    例えば品物が 13 個ある場合
    品物を 1 個入れたとき
    品物を 2 個入れたとき
    品物を 4 個入れたとき
    品物を 6 個入れたとき
    をそれぞれ計算する。これで計算量が O(NW log m) となり間に合う。
*/

int main()
{
    int n, w;
    cin >> n >> w;
    vector<int> value(n), weight(n), items(n);
    for (int i = 0; i < n; i++)
        cin >> value[i] >> weight[i] >> items[i];
    vector<int> dp(w + 1, -1);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        int m = items[i];   // 最大個数
        for (int j = 0; j < 15; j++) {
            int num = 1<<j;     // i番目を加えるか加えないか
            chmin(num, m);
            if (num == 0) break;

            for (int k = w - 1; k >= 0; k--)
            {
                if (dp[k] == -1) continue;
                if (k + weight[i] * num <= w)
                    chmax(dp[k + weight[i] * num], dp[k] + value[i] * num);
            }
            m -= num;
        }
    }
    int ans = 0;
    for (int i = 0; i < w + 1; i++)
        chmax(ans, dp[i]);
    cout << ans << endl;
    return 0;
}