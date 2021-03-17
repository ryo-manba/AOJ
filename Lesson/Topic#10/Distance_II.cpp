#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 4000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;

/* ミンコフスキー距離
    p = 1   マンハッタン距離
    p = 2   ユークリッド距離
    p = INF チェビシェフ距離
*/

int main()
{
    int n;
    cin >> n;
    vector<double> x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n; i++) cin >> y[i];

    double a_1 = 0, a_2 = 0, a_3 = 0, a_e = 0;
    for (int i = 0; i < n; i++)
    {
        a_1 += fabs(x[i] - y[i]); 
        a_2 += ((x[i] - y[i]) * (x[i] - y[i]));
        a_3 += fabs(x[i] - y[i]) * fabs(x[i] - y[i]) * fabs(x[i] - y[i]);
        a_e = max(a_e, fabs(x[i]- y[i]));
    }

    printf("%.6f\n", a_1);
    printf("%.6f\n", sqrt(a_2));
    printf("%.6f\n", pow(a_3, 1.0/3.0));
    printf("%.6f\n", a_e);
    return 0;
}