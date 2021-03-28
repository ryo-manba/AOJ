#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10

/*  最長共通部分列(LCS)
    S1とS2の要素から順番を保ったまま任意の数の文字を選択した場合に
    同一となる文字列のうち, 最長のものを指す。
    必ずしも要素同士は隣り合っている必要がない
    
    dp[i][j] は下記の最大値:
    dp[i][j-1]        ＃左から進んでくるケース（文字列 1 から一文字削除）
    dp[i-1][j]        ＃上から進んでくるケース（文字列 2 から一文字削除）
    dp[i-1][j-1] + 1  ＃LCS の候補とみなした場合（同じ文字の場合のみ）
*/

void lcs(string x, string y)
{
    // xとyの長さを取って、dpテーブルを用意する
   int n = x.length();
   int m = y.length();
   vector<vector<int> > dp(n+1, vector<int>(m+1, 0));
    // x[n]がn番目の文字になるように、一文字目に空白を入れる
   x = ' ' + x;
   y = ' ' + y;
   for(int i = 1; i <= n; i++){
       for(int j = 1; j <= m; j++){
           if(x[i] == y[j]){
               dp[i][j] = dp[i-1][j-1]+1;
           }else{
               dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
           }
       }
   }
   cout << dp[n][m] << endl;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string a, b;
        cin >> a >> b;
        lcs(a, b);
    }
    return 0;
}