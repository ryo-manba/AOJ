#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define INF 1e9
#define INFL 1e18
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int mini = a[0];
    int maxi = -INF;
    for (int i = 1; i < n; i++) 
    {
        maxi = max(maxi, a[i] - mini);
        mini = min(mini, a[i]);
    }
    cout << maxi << endl;
    return 0;
}