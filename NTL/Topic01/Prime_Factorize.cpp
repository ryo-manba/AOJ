#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

//  素因数分解

vector<int> ans;

void prime(int n)
{
    for (int i = 2; n > 1; i += 2)
    {
        if (i == 4) i--;
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                n /= i;
                ans.push_back(i);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    cout << n << ":";
    prime(n);
    for (auto a : ans)
    {
        cout << " " << a;
    }
    cout << endl;

    return 0;
}