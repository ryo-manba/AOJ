#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

string big = "overflow";

string solve(string x, string y)
{
    if (x.size() > 80 || y.size() > 80)
        return big;

    string ans = "";
    vector<int> xa(80), ya(80), za(80);
    for (int i = 0; i < x.size(); i++) xa[i] = x[x.size() - 1 - i] - '0';
    for (int i = 0; i < y.size(); i++) ya[i] = y[y.size() - 1 - i] - '0';
    for (int i = 0; i < 80; i++)
    {
        za[i] += xa[i] + ya[i];
        if (za[i] >= 10)
        {
            za[i] -= 10;    // 桁上り
            if (i == 79)    // 80桁を超える場合
                return big;
            else
                za[i + 1]++;
        }
    }

    int flag = 0;
    for (int i = 79; i >= 0; i--)
    {
        if (flag == 0 && za[i] == 0)
            continue;
        else
        {
            flag = 1;
            ans += (za[i] + '0');
        }
    }
    if (ans == "")
        return "0";
    else 
        return ans;   
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string a, b;
        cin >> a >> b;
        cout << solve(a, b) << endl;
    }
    return 0;
}