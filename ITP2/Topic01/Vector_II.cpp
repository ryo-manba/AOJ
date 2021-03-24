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
    vector<vector<int>> vec(n);

    for (int i = 0; i < q; i++)
    {
        int first_order, second_order, num;
        cin >> first_order >> second_order;

        if (first_order == 0)   // 末尾に要素を挿入
        {
            cin >> num;
            vec[second_order].push_back(num);
        }
        if (first_order == 1)   // 全ての要素を出力
        {
            for (int i = 0; i < vec[second_order].size(); i++)
            {
                if (i) cout << " ";
                cout << vec[second_order][i];
            }
            cout << endl;
        }
        if (first_order == 2)   // 空にする
        {
            vec[second_order].clear();
        }
    }
    return 0;
}