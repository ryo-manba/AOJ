#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 4000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;

/*  二分探索 
    1.探索の範囲内の中央の要素を調べる。
    2.目的のキーと中央の要素のキーが一致すれば探索を終了。
    3.目的のキーが中央の要素のキーよりも小さければ前半部分を、大きければ後半部分を探索の範囲として 2.へ戻る
*/

int main()
{
    int n, q;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    cin >> q;
    vector<int> t(q);
    for (int i = 0; i < q; i++) cin >> t[i];

    int cnt = 0;    
    for (int i = 0; i < q; i++) 
    {
        int left = 0, right = n;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (s[mid] == t[i])     // 値が見つかったらbreak
            {
                cnt++;
                break;
            }
            else if (s[mid] > t[i]) right = mid - 1;
            else if (s[mid] < t[i]) left = mid + 1;
        }
    }
    cout << cnt << endl;
    return 0;
}