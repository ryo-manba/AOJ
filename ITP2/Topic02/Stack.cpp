#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10

int main()
{
    int n, q;
    cin >> n >> q;
    vector<stack<int>> sta(n);
    for (int i = 0; i < q; i++)
    {
        int first_order, second_order, num;
        cin >> first_order >> second_order;
        if (first_order == 0)       // 要素を挿入
        {
            cin >> num;
            sta[second_order].push(num);
        }
        if (first_order == 1)       // 要素を出力
        {
            if (!sta[second_order].empty())
                cout << sta[second_order].top() << endl;
        }
        if (first_order == 2)       // 要素を削除
        {
            if (!sta[second_order].empty())
                sta[second_order].pop();
        }
    }
    return 0;
}