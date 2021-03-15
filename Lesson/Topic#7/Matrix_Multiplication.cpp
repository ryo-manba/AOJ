#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 4000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;

int main()
{
    int n, m, l;
    cin >> n >> m >> l;
    ll a[105][105] = {{}};
    ll b[105][105] = {{}};
    ll c[105][105] = {{}};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < l; j++) {
            cin >> b[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < l; j++) {
            for (int k = 0; k < m; k++) {
                c[i][j] += (a[i][k] * b[k][j]);
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < l; j++) {
            cout << c[i][j];
            if (j == l - 1) cout << endl;
            else cout << " ";
        }
    }   
    return 0;
}