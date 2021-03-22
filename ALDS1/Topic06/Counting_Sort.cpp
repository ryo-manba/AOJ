#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10

/*  計数ソート (バケットソート)
    要素の値が小さいことに着目して，各要素に対して自身の値より小さい要素数を数えることにする.
    これは累積和を用いると，計算時間と領域量は互いに O(n+k) で求めることができる.
*/

const int MAX = 100000;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // 各要素の個数をカウントする
    int num[MAX] = {0};
    for (int i = 0; i < n; i++)
    {
        num[a[i]]++;
    }

    // num の累積和をとる
    int sum[MAX] = {0};
    for (int i = 0; i < MAX; i++)
    {
        sum[i] = sum[i - 1] + num[i];
    }

    // sum を元にソート
    vector<int> sorted(n);
    for (int i = n - 1; i >= 0; i--)
    {
        sorted[--sum[a[i]]] = a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << sorted[i];
        if (i == n - 1) cout << endl;
        else    cout << " ";
    }
    return 0;
}