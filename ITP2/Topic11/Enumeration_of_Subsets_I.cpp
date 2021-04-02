#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

// 部分集合の列挙

int main()
{
    int n;
    cin >> n;

    for (int bit = 0; bit < (1 << n); bit++)
    {
        vector<int> s;
        for (int i = 0; i < n; i++)
        {
            if (1 << i & bit)
                s.push_back(i);
        }
        cout << bit << ":";
        for (int i = 0; i < s.size(); i++)
        {
            cout << " " << s[i];
        }
        cout << endl;
    }
    return 0;
}