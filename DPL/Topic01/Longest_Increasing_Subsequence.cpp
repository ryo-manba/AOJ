#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10

/*  最長増加部分列(LIS)
    数列の順番を変えずに取り出したときに、増加列となる中で最大の長さのもの。
    数列 a1, a2, a3 が増加列であるとは, a1 <= a2 <= a3 が成り立つこと。
*/

int Lis(vector<int> &a)
{
    vector<int> dp;
    for (auto x : a)
    {
        auto itr = lower_bound(dp.begin(), dp.end(), x);
        if (itr != dp.end())   // これまでに出てきた要素より小さい場合はその値で更新する
            *itr = x;
        else
            dp.push_back(x);   // x がlis の要素の中で一番大きい場合
    }
    return dp.size();
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ans = Lis(a);
    cout << ans << endl;
    return 0;
}