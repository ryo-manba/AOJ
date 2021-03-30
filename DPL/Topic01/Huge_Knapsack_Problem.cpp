#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

/*  巨大ナップサック問題
    O(NW)の計算量では不十分なため，N が小さいのを利用して解く。
    品物の選び方は 2N通りあるので，計算量は最大で 2^40。
    半分に分割する方法を考えると 2^20 となる(半分全列挙)
    前半分から重さと価値の総和が W1, V1 となる選び方をする。
    同様に，後ろ半分から重さと価値の総和が W2,V2となる選び方をする。
    W1+W2≤W を満たす場合の V1+V2 の最大値が答え。

*/

const int MAX_N = 40;

int main()
{
    int N;
    ll W, v[MAX_N], w[MAX_N];
    vector<pair<ll, ll>> p; // (weight, value)
    cin >> N >> W;
    for (int i = 0; i < N; i++)
        cin >> v[i] >> w[i];
    
    int N2 = N / 2;
    for (int i = 0; i < 1<<N2; i++) 
    {
        ll sw = 0, sv = 0;
        for (int j = 0; j < N2; j++) 
        {
            if (i >> j & 1)
            {
                sw += w[j];
                sv += v[j];
            }
        }
        p.push_back(make_pair(sw, sv));
    }
    sort(p.begin(), p.end());
    int m = 1;
    for (int i = 1; i < 1 << N2; i++)
    {
        if (p[m - 1].second < p[i].second)
        {
            p[m] = p[i];
            m++;
        }
    }
    ll res = 0;
    for (int i = 0; i < 1 << (N - N2); i++)
    {
        ll sw = 0, sv = 0;
        for (int j = 0; j < N - N2; j++)
        {
            if (i >> j & 1) 
            {
                sw += w[N2 + j];
                sv += v[N2 + j];
            }
        }
        if (sw <= W)
        {
            pair<ll, ll> P = make_pair(W - sw, INF);
            ll tv = (lower_bound(p.begin(), p.begin() + m, P) - 1)->second;
            res = max(res, sv + tv);
        }
    }
    cout << res << endl;
    return 0;
}