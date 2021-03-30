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
    int n;
    cin >> n;
    map<string, int> mp;
    for (int i = 0; i < n; i++)
    {
        int order, num;
        string color;
        cin >> order;
        if (order == 0)
        {
            cin >> color >> num;
            mp[color] = num;
        }
        if (order == 1)
        {
            cin >> color;
            auto it = mp.find(color);
            if (it != mp.end())
               cout << it->second << endl;
            else
                cout << 0 << endl;
        }
        if (order == 2)
        {
            cin >> color;
            auto it = mp.find(color);
            if (it != mp.end())
                it = mp.erase(it);
        }
        if (order == 3)
        {
            string left, right;
            cin >> left >> right;
            auto it = mp.lower_bound(left);
            auto last = mp.upper_bound(right);
            while (it != last)
            {
                cout << it->first << " " << it->second << endl;
                it++;
            }
        }
    }
    return 0;
}