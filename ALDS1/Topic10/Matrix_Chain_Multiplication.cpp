#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10

/*  連鎖行列積 (行列を乗算するとき、計算回数を最小にする積の順序)
    1.行列どうしのかけ算は、「左の列数」と「右の行数」が等しくないとかけ算できない
    2.n * m 行列と m * l 行列の乗算は n * m * l 回のスカラー積が必要

    括弧付けの仕方に寄って計算コストが変化する
    サイズが3の連鎖行列 , A_1:10x100, A_2:100x5, A_3:5x50 とする。
    ((A_1 A_2) A_3) => A_1 A_2 の計算に 10x100x5 = 5000回、結果は B(サイズ10x5) とする。B A_3 の計算に 10x5x50 = 2500回。総計算回数7500。
    (A_1 (A_2 A_3)) => A_2 A_3 の計算に 100x5x50 = 25000回、結果は C(サイズ100x50) とする。A_1 C の計算に10x100x50 = 50000回。総計算回数75000。
    10倍計算回数に差が出る。
*/

const int SIZE = 100;

int main()  
{
    int n;
    int p[SIZE], cost[SIZE][SIZE];
    cin >> n;

    // 行列の次元を行、列の順番で読み込む
    for (int i = 0; i < n; i++) cin >> p[i] >> p[i + 1];
    
    // 初期値
    for (int i = 1; i <= n; i++) cost[i][i] = 0;

    // 行列の個数
    for (int l = 2; l <= n; l++) 
    {
        for (int i = 1; i <= n - l + 1; i++)
        {
            int j = i + l - 1;
            cost[i][j] = INF;
            for (int k = i; k <= j - 1; k++)
            {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k + 1][j] + p[i - 1] * p[k] * p[j]);
            }
        }
    }
    cout << cost[1][n] << endl;    
    return 0;
}