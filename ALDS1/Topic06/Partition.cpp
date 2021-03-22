#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10

/*  パーティション 
    配列の末尾の要素を基準として、それ以下の大きさの要素とそれより大きい要素に分ける。
    配列の先頭から順番に大きさを検討して、「x以下のグループ」、「xより大きいグループ」に移動していく。
    クイックソートで利用される。
*/

int partition(int *a, int p, int r)
{
    int x = a[r];
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (a[j] <= x)
        {   
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int index = partition(a, 0, n - 1);
    for (int i = 0; i < n; i++) 
    {
        if (i) cout << " ";
        if (i == index) cout << "[" << a[i] << "]";
        else    cout << a[i];
    }
    cout << endl;
    return 0;
}