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
    string s;
    cin >> s;
    vector<string> ans;
    while(s[0] != '-')
    {
        int m;
        cin >> m;
        for (int i = 0; i < m; i++) 
        {
            int h;
            cin >> h;
            int sz = s.size();
            string sub = s.substr(0,h);
            string sub2 = s.substr(h, sz);
            s = sub2 + sub;
        }
        ans.push_back(s);
        cin >> s;
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}