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
    list<int> lst;
    auto itr = lst.end();
    for (int i = 0; i < n; i++)
    {
        int order, num;
        cin >> order;
        if (order == 0)     // カーソルが指す要素の直前にnum を挿入
        {
            cin >> num;
            itr = lst.insert(itr, num);
        }
        if (order == 1)     // num が正の場合、カーソルを後方に移動 
        {                   //  負の場合、カーソルを前方に移動            
            cin >> num;
            if (num > 0)
            {
                for (int i = 0; i < num; i++)
                    itr++;
            }
            else
            {
                for (int i = 0; i > num; i--)
                    itr--;
            }
        }
        if (order == 2)     // 削除、カーソルは一つ後方を指す
            itr = lst.erase(itr);
    }

    // 要素を先頭から出力
    for (auto itr = lst.begin(); itr != lst.end(); itr++)
    {
        cout << *itr << endl;
    }
    return 0;
}