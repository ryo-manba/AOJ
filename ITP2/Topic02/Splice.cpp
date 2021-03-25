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
    vector<list<int>> lst(n);
    for (int i = 0; i < q; i++)
    {
        int first_order, second_order, num;
        cin >> first_order >> second_order;
        if (first_order == 0)       // 要素を挿入
        {
            cin >> num;
            lst[second_order].push_back(num);
        }
        if (first_order == 1)       // 要素を列挙
        {
            int i = 0;
            if (!lst[second_order].empty())
            {
                for (auto x : lst[second_order])  
                {
                    if (i) cout << " ";
                    cout << x;
                    i++;
                }
            }
            cout << endl;
        }
        if (first_order == 2)       // 要素を接合
        {
            cin >> num;
            lst[num].splice(lst[num].end(), move(lst[second_order]));
        }
    }
    return 0;
}