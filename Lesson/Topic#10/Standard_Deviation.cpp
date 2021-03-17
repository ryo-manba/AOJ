#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 4000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;

/* 標準偏差
    対象データがどれくらい散らばっているかを表す指標。
    対象データの値と平均との間にある差を2乗したものを合計した上で、
    データの総数で割った正の平方根から求められる。

    1.データ全体の平均値を出す
    2.偏差（各データから平均値を差し引いた値）を求める
    3.2で算出した偏差を2乗する
    4.3で出した偏差の合計を出す
    5.偏差の合計をデータの総数で割って分散を求める
    6.5で出した分散の正の平方根を求めて標準偏差を算出する
*/

int main()
{
    int n;
    cin >> n;
    while (n != 0)
    {
        double sum = 0;
        double avg = 0;
        vector<double> s(n);
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
            sum += s[i];
        }
        avg = sum / n;
        double avg_sum = 0;
        for (int i = 0; i < n; i++)
        {
            s[i] -= avg;
            s[i] *= s[i];
            avg_sum += s[i];
        }
        avg_sum /= n;
        double ans = 0;
        ans = sqrt(avg_sum);
        printf("%.8f\n", ans);
        cin >> n;
    }   
    return 0;
}