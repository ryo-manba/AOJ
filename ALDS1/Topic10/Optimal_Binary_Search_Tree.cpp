#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10

/*  最適二分探索木(Hu-Tucker)
    検索のみで挿入と削除をしないときに、平衡二分探索木よりも検索時間が
    短くなるデータ構造。表を埋めることで、計算を高速に行う。

    検索される要素の確率分布が分かっているときに、その確率分布に対して，
    検索にかかる時間が平均的に最も少なくなるような木を構築することが可能
*/

int n;
double p[550], q[550];
double M[550][550], P[550][550];

void setP()
{
    for (int i = 0; i < n + 1; i++) P[i][i] = q[i]; // 終端をq[i]で埋める
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n + 1; j++)
        {
            P[i][j] = P[i][j - 1] + p[j] + q[j];    // p[i][i + 1]をp[i] + p[i + 1] + q[i + 1]で埋める
        }
    }
}

void setM()
{
    for (int i = 0; i < n + 1; i++) M[i][i] = q[i]; // 終端をq[i]で埋める
    for (int l = 1; l < n + 1; l++)
    {
        for (int i = 0; i < n - l + 1; i++)
        {
            int j = i + l;
            M[i][j] = INF;
            for (int k = i + 1; k < j + 1; k++)
            {
                M[i][j] = min(M[i][j], M[i][k - 1] + M[k][j] + P[i][j]);
            }
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i < n + 1; i++) cin >> p[i];
    for (int i = 0; i < n + 1; i++) cin >> q[i];

    setP();
    setM();

    printf("%.7f\n", M[0][n]);
    return 0;
}