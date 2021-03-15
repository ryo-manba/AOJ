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
    int a[4][11] = {0};
    int b[4][11] = {0};
    int c[4][11] = {0};
    int d[4][11] = {0};

    for (int i = 1; i <= n; i++)
    {
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        if (A == 1) 
        {
            a[B][C] += D;
            if (a[B][C] > 9) a[B][C] = 9;
            if (a[B][C] < 0) a[B][C] = 0;
        }
          if (A == 2) 
        {
            b[B][C] += D;
            if (b[B][C] > 9) b[B][C] = 9;
            if (b[B][C] < 0) b[B][C] = 0;
        }  
        if (A == 3)
        {
            c[B][C] += D;
            if (c[B][C] > 9) c[B][C] = 9;
            if (c[B][C] < 0) c[B][C] = 0;
        }  
        if (A == 4) 
        {
            d[B][C] += D;
            if (d[B][C] > 9) d[B][C] = 9;
            if (d[B][C] < 0) d[B][C] = 0;
        }
    }

    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 10; j++) {
            cout << " " << a[i][j];
            if (j == 10) cout << endl;
        }
    }
    cout << "####################" << endl;

  for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 10; j++) {
            cout << " " << b[i][j];
            if (j == 10) cout << endl;
        }
    }
    cout << "####################" << endl;

  for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 10; j++) {
            cout << " " << c[i][j];
            if (j == 10) cout << endl;
        }
    }

    cout << "####################" << endl;

  for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 10; j++) {
            cout << " " << d[i][j];
            if (j == 10) cout << endl;
        }
    }
}