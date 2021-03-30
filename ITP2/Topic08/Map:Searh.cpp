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
        cin >> order >> color;
        if (order == 0)
        {
            cin >> num;
            mp[color] = num;
        }
        if (order == 1)
            cout << mp[color] << endl;
    }
    return 0;
}