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
    int q;
    cin >> q;
    bitset<64> bit(0);
    for (int i = 0; i < q; i++)
    {
        int order, num;
        bool check = false;
        cin >> order;
        if (order == 0)
        {
            cin >> num;
            if(bit.test(num)) check = true;
        }
        if (order == 1)
        {
            cin >> num;
            bit.set(num);
        }
        if (order == 2)
        {
            cin >> num;
            bit.reset(num);
        }
        if (order == 3)
        {
            cin >> num;
            bit.flip(num);
        }
        if (order == 4)
        {
            if (bit.all()) check = true;
        }
        if (order == 5)
        {
            if (bit.any()) check = true;
        }
        if (order == 6)
        {
            if (bit.none()) check = true;
        }
        if (order == 7)
        {
            cout << bit.count() << endl;
        }
        if (order == 8)
        {
            unsigned long long result = bit.to_ullong();
            cout << result << endl;
        }
        if (order == 0 || order == 4 || order == 5 || order == 6)
        {
            if (check == true) cout << 1 << endl;
            else    cout << 0 << endl;
        }
    }
    return 0;
}