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
    int n;
    cin >> n;
    vector<int> S(14,0), H(14,0), C(14,0), D(14,0);
    for (int i = 0; i < n; i++)
    {
        char c;
        int a;
        cin >> c >> a;
        if (c == 'S') S[a]++;
        if (c == 'H') H[a]++;
        if (c == 'C') C[a]++;
        if (c == 'D') D[a]++;
    }

    int i = 1;
    while(i <= 13)
    {
        if (S[i] == 0)
        {
            cout << 'S' << " " << i << endl;
        }
        i++;
    }

    i = 1;
    while(i <= 13)
    {
        if (H[i] == 0)
        {
            cout << 'H' << " " << i << endl;
        }
        i++;
    }
    
    i = 1;
    while(i <= 13)
    {
        if (C[i] == 0)
        {
            cout << 'C' << " " << i << endl;
        }
        i++;
    }
    
    i = 1;
    while(i <= 13)
    {
        if (D[i] == 0)
        {
            cout << 'D' << " " << i << endl;
        }
        i++;
    }
    return 0;
}