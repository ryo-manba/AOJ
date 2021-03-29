#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

/*  編集距離(レーベンシュタイン距離)
    以下３種類の操作によって、１つの文字列を別の文字列に変形するのに必要な手順の最小回数
    挿入: 文字列に１つの文字を挿入する。
    削除: 文字列から１つの文字を削除する。
    置換: 文字列の中の１文字を別な文字に置き換える。
*/

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    int sz1 = (int)s1.size();
    int sz2 = (int)s2.size();

    // 2次元配列を作る
    vector<vector<int> > dp(sz1 + 1, vector<int> (sz2 + 1, INF));
    for (int i = 0; i <= sz1; i++) dp[i][0] = i;
    for (int i = 0; i <= sz2; i++) dp[0][i] = i;

    for (int i = 0; i < sz1; i++) {
        for (int j = 0; j < sz2; j++) {
            if (s1[i] == s2[j]) chmin(dp[i + 1][j + 1], dp[i][j]);
            chmin(dp[i + 1][j + 1], dp[i][j + 1] + 1);
            chmin(dp[i + 1][j + 1], dp[i + 1][j] + 1);
            chmin(dp[i + 1][j + 1], dp[i][j] + 1); 
        }
    }

    cout << dp[sz1][sz2] << endl;
    return 0;
}