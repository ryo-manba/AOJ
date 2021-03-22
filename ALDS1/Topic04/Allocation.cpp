#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10

int n, k;
vector<int> w(100000);

bool check(int x)
{
    ll cost = 0, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cost += w[i];
        while (cost > x)
        {
            // 1つでコストを超えたらfalse
            cost = w[i];    
            cnt++;
            // コストを超える組み合わせがk 回を超えたらfalse
            if (cnt == k)
                return false;
        }
    }
    return true;
}

int main()
{
    cin >> n >> k;
    ll sum = 0;
    for (int i = 0; i < n; i++) 
    {
        cin >> w[i];
        sum += w[i];
    }
    ll l = 0, r = sum, mid;
    while (l < r)
    {
        mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else    l = mid + 1;
    }

    cout << l << endl;
    return 0;
}