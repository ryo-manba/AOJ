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
    multimap<string, int> mp;
    for (int i = 0; i < n; i++)
    {
        int order, num;
        string color;
        cin >> order;
        if (order == 0)
        {
            cin >> color >> num;
            mp.insert({color, num});
        }
        if (order == 1)
        {
            cin >> color;
            pair p = mp.equal_range(color);
            for (auto it = p.first; it != p.second; it++)
            {
                cout << it->second << endl;
            }
        }
        if (order == 2)
        {
            cin >> color;
            mp.erase(color);
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