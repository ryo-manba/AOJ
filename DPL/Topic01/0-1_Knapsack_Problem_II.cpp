#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


const int MAX_N = 110;
const int MAX_V = 100100;

int main()
{
    ll n, w;
    cin >> n >> w;
    vector<ll> value(n), weight(n);
    for (int i = 0; i < n; i++)
        cin >> value[i] >> weight[i];
    vector<vector<ll> > dp(MAX_N, vector<ll> (MAX_V, INFL));
    dp[0][0] = 0;

    for (int i = 0; i < n; i++) {
        for (int sum_v = 0; sum_v < MAX_V; sum_v++) {

            // i 番目の品物を選ぶ場合
            if (sum_v - value[i] >= 0) 
                chmin(dp[i + 1][sum_v], dp[i][sum_v - value[i]] + weight[i]);

            // i 番目の品物を選ばない場合
            chmin(dp[i + 1][sum_v], dp[i][sum_v]);
        }
    }

    ll ans = 0;
    for (int sum_v = 0; sum_v < MAX_V; sum_v++) {
        if (dp[n][sum_v] <= w)
            ans = sum_v;
    }
    cout << ans << endl;
    return 0;
}