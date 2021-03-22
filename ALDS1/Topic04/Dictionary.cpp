#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10

int main()
{
    int n, h;
    cin >> n;
    map<string, int> dict;
    string order;
    vector<string> ans;
    for (int i = 0; i < n; i++)
    {
        string order, str;
        cin >> order >> str;
        if (order == "insert")
        {
            dict[str]++;
        }
        if (order == "find")
        {
            if (dict[str])
                cout << "yes" << endl;
            else
                cout << "no" << endl;
        }
    }
    return 0;
}