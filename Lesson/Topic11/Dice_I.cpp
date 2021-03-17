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
    int top()       // サイコロの上面
    {
        return s[0];
    }
};

int main()
{
    Dice d;
    for (int i = 0; i < 6; i++) 
    {
        cin >> d.s[i];      // メンバ変数に値を読み込む
    }

    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) 
    {
        d.roll(s[i]);       // 転がした方向を読み込んで実行する
    }
    cout << d.top() << endl;    // 上面を表示する
    return 0;
}