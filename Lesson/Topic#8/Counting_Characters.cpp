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
    vector<int> ans(123, 0);
    string s;
    while(getline(cin, s))
    {    
        int change = 'a' - 'A';
        int i = 0;
        while (i != s.size())
        {
            if (s[i] >= 'A' && s[i] <= 'Z') s[i] += change;
            i++;
        }

        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                int tmp = s[i];
                ans[tmp]++;
            }
        }
    }

    char a = 'a';
    for (int i = 97; i <= 122; i++) {
        printf("%c : %d\n", a, ans[i]);
        a++;
    }
    return 0;
}