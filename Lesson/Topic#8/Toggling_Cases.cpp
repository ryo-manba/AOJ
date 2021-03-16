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
    getline(cin, s);
    int change = 'a' - 'A';
    int i = 0;
    while (i != s.size())
    {
        if (s[i] >= 'A' && s[i] <= 'Z') s[i] += change;
        else if (s[i] >= 'a' && s[i] <= 'z') s[i] -= change;
        cout << s[i];
        i++;
    }
    cout << endl;
    return 0;
}