#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 4000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;

struct Dice {
    int s[6];
    void roll(char c)   // 転がした方向に対応して値を変更
    {
        int b;
        if (c == 'E')   // East(東)
        {
            b = s[0];
            s[0] = s[3];
            s[3] = s[5];
            s[5] = s[2];
            s[2] = b;
        }

        if (c == 'W')   // West(西)
        {
            b = s[0];
            s[0] = s[2];
            s[2] = s[5];
            s[5] = s[3];
            s[3] = b;
        }

        if (c == 'N')   // North(北)
        {
            b = s[0];
            s[0] = s[1];
            s[1] = s[5];
            s[5] = s[4];
            s[4] = b;
        }

        if (c == 'S')   // South(南)
        {
            b = s[0];
            s[0] = s[4];
            s[4] = s[5];
            s[5] = s[1];
            s[1] = b;
        }

        if (c == 'R')   // サイコロの前面が出るまでずらす
        {
            b = s[1];
            s[1] = s[2];
            s[2] = s[4];
            s[4] = s[3];
            s[3] = b;
        }
    }

    int top()           // サイコロの上面
    {
        return s[0];
    }
    
    int front()         // サイコロの前面
    {
        return s[1];
    }

    int right()         // サイコロの右面
    {
        return s[2];
    }

    int left()
    {
        return s[3];    // サイコロの左面
    }
};

bool    same(Dice a, Dice b)    // さいの目が同じかどうか
{
    for (int i = 0; i < 6; i++)
    {
        if (a.s[i] != b.s[i])
            return false;
    }
    return true;
}


int main()
{
    int n;
    cin >> n;

    Dice d[n]; 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> d[i].s[j];
        }
    }

    bool check = true;
    for (int k = 0; k < n - 1; k++) {
        for (int l = k + 1; l < n; l++) {
            bool check_d = false;
            for (int i = 0; i < 4; i++) {
                d[l].roll('R');
                for (int j = 0; j < 4; j++) {
                    d[l].roll('N');
                    if (same(d[k], d[l])) check_d = true;
                }
            }
            d[l].roll('E');
            for (int j = 0; j < 4; j++) {
                d[l].roll('N');
                if (same(d[k],d[l])) check_d = true;
            }

            d[l].roll('W');
            d[l].roll('W');
            for (int j = 0; j < 4; j++)
            {
                d[l].roll('N');
                if (same(d[k], d[l])) check_d = true;
            }
            if (check_d) check = false;
        }
    }
    string ans;
    if (check) ans = "Yes";
    else    ans = "No";
    cout << ans << endl;
    return 0;
}