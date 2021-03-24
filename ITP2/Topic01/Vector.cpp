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
    vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        int order, num;
        cin >> order;
        if (order == 0)     // 末尾に要素を追加
        {
            cin >> num;
            vec.push_back(num);
        }
        if (order == 1)     // 要素を出力
        {
            cin >> num;
            cout << vec[num] << endl;
        }
        if (order == 2)     // 末尾の要素を削除
        {
            vec.pop_back();
        }
    }
    return 0;
}