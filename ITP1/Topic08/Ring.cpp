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
    string s, p;
    cin >> s >> p;
    string ss = s + s;
    if (ss.find(p) != string::npos)
        cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}