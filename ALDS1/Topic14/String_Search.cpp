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
    string t, p;
    cin >> t >> p;
    if (t.size() < p.size()) return 0;
    for (int i = 0; i <= t.size() - p.size(); i++)
    {
        if (p == t.substr(i, p.size()))
            printf("%d\n", i);
    }
    return 0;
}