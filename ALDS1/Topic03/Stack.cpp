#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10

// 逆ポーランド記法

struct Stack {
    int table[1000];
    int top;

    // 初期化
    void init()             
    {
        top = 0;
    }

    // 空か調べる
    bool isEmpty()          
    {
        return top == 0;
    }

    // 先頭に要素を追加
    void push(int x)        
    {
        table[top] = x;
        top++;
    }

    // 先頭から要素を取り出す
    int pop()               
    {
        if (isEmpty())
        {
            return 0;
        }
        top--;
        return table[top];
    }
};

// オペランドに合わせて計算する
int calc (int x, string op, int y)     
{
    if (op == "+") return x + y;
    if (op == "-") return x - y;
    if (op == "*") return x * y;
}

int main()
{
    string s;
    int numA, numB;
    Stack sta;
    sta.init();

    while (cin >> s)
    {
        if (s == "+" || s == "-" || s == "*")
        {
            numA = sta.pop();
            numB = sta.pop();
            sta.push(calc(numB, s, numA));
        }
        else
        {
            numA = 0;
            for (int i = 0; i < s.size(); i++)
            {
                numA *= 10;
                numA += s[i] - '0';
            }
            sta.push(numA);
        }
    }
    cout << sta.pop() << endl;
    return 0;
}