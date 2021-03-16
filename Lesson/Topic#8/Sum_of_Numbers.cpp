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
    vector<int> ans;
    while (1)
    {
        string a;
        cin >> a;
        if (a[0] == '0') break;
        int sum = 0;
        for (int i = 0; i < a.size(); i++) {
            sum += a[i] - '0';
        }
        ans.push_back(sum);
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}