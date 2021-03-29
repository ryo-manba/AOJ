#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

void print(vector<int> &v)
{
    int i = 0;
    for (auto a : v)
    {
        if (i) cout << " ";
        cout << a;
        i++;
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    if (prev_permutation(a.begin(), a.end()))
    {
        print(a);
        next_permutation(a.begin(), a.end());
    }
    else
        next_permutation(a.begin(), a.end());   // falseの場合でも順列は生成されてしまうため
    
    print(a);
    if (next_permutation(a.begin(),a.end()))
        print(a);
    return 0;
}