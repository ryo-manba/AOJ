#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 4000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;

int main()
{
    double a, b, c;
    cin >> a >> b >> c;     // 2辺 a, bとその間の角c
    double PI = acos(-1);   // 逆余弦 acos 関数に -1 を与えることでPI(円周率)が求められる
    printf("%.8f\n", a * b * sin(c * PI / 180) / 2);    //  面積
    printf("%.8f\n", sqrt(a * a + b * b - 2 * a * b * cos(c * PI / 180)) + a + b);  //　周の長さ
    printf("%.8f\n", b * sin(c * PI / 180));    // a を底辺としたときの高さ
    return 0;
}