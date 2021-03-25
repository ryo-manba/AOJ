#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10

/*  完全二分木
    1. すべての枝分かれが2つ
    2. すべての枝分かれの先っぽが最初の地点から同じ距離

    二分ヒープ
    子要素は親要素より常に大きいか等しい（または常に小さいか等しい）
    という制約を持つ木構造
*/

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    /*  節点の添え字に対して
        parent = i / 2
        left   = i * 2
        right  = i * 2 + 1
    */
    for (int i = 0; i < n; i++)
    {
        printf("node %d: key = %d, ", i + 1, a[i]);
        if (i)
            printf("parent key = %d, ", a[(i - 1) / 2]);    
        if (i * 2 + 1 < n)
            printf("left key = %d, ", a[i * 2 + 1]);
        if (i * 2 + 2 < n)
            printf("right key = %d, ", a[i * 2 + 2]);
        cout << endl;    
    }
    return 0;
}