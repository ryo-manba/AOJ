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
    int cnt = 0;
    while(1)
    {
        string t;
        cin >> t;
        if (t == "END_OF_TEXT") break;
        transform(s.begin(),s.end(),s.begin(), ::toupper);
        transform(t.begin(),t.end(),t.begin(), ::toupper);
        if (s == t) cnt++;
    }
    cout << cnt << endl;
    return 0;
}