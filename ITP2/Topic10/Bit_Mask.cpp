#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main()
{
    int n,q;
    cin >> n;
    vector<bitset<64>> mask(n);
    bitset<64> bit;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        for (int j = 0; j < a; j++)
        {
            int b;
            cin >> b;
            mask[i][b] = 1;
        }
    }
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int order, index;
        cin >> order >> index;
        if (order == 0)     // フラグが ON の場合 1
            cout << bit[index] << endl; 
        if (order == 1)     // マスクが表すフラグを ON
            bit |= mask[index];         
        if (order == 2)     // マスクが表すフラグを OFF
            bit &= ~mask[index];        
        if (order == 3)     // マスクが表すフラグを反転
            bit ^= mask[index];         
        if (order == 4)     // マスクが表すフラグが全てON の場合 1
            cout << ((bit & mask[index]) == mask[index]) << endl;   
        if (order == 5)     // マスクが表すフラグのいずれかが ON の場合 1
            cout << (bit & mask[index]).any() << endl;
        if (order == 6)     // マスクが表すフラグが全て OFF の場合 1
            cout << (bit & mask[index]).none() << endl;
        if (order == 7)     // マスクが表すフラグの ON になっている数
            cout << (bit & mask[index]).count() << endl;
        if (order == 8)     // マスクが表すフラグの整数値を出力
            cout << (bit & mask[index]).to_ullong() << endl;
    }
    return 0;
}