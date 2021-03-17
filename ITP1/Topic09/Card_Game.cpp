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
    int a_num = 0, b_num = 0;
    for (int i = 0; i < n; i++)
    {
        string a, b;
        cin >> a >> b;
        if (a > b) a_num += 3;
        if (b > a) b_num += 3;
        if (a == b)
        {
            a_num++;
            b_num++;
        }
    }
    cout << a_num << " " << b_num << endl;
    return 0;
}