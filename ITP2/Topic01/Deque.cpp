#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10

int main()
{
    int n;
    cin >> n;
    deque<int> dec;
    for (int i = 0; i < n; i++)
    {
        int first_order, second_order, num;
        cin >> first_order;
        if (first_order == 0)       // 要素の追加
        {
            cin >> second_order >> num;
            if (second_order == 0)
                dec.push_front(num);
            else
                dec.push_back(num);
        }
        if (first_order == 1)       // 要素の出力
        {
            cin >> num;
            cout << dec[num] << endl;
        }
        if (first_order == 2)       // 要素の削除
        {
            cin >> second_order;
            if (second_order == 0)
                dec.pop_front();
            else
                dec.pop_back();       
        }
    }
    return 0;
}