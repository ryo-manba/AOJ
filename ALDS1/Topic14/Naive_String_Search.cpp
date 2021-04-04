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

    bool check = true;
    for (int i = 0; i < t.size(); i++)
    {
        if (t[i] == p[0])
        {
            int j = 0, k = i;
            while (p[j])
            {
                if (t[k] != p[j])
                {
                    check = false;
                    break;
                }
                k++;
                j++;
            }
            if (check) cout << i << endl;
            check = true;
        }
    }
    return 0;
}