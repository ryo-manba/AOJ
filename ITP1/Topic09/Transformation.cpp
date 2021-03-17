#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 4000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;

void    print(int a, int b, char str[])
{
    for (int i = a; i <= b; i++)
    {
        cout << str[i];
    }
    cout << endl;
}

void  replace(int a, int b, char str[])
{
    string replace_str;
    cin >> replace_str;
    int str_len = b - a + 1;
    for (int i = 0; i < str_len; i++)
    {
        str[a + i] = replace_str[i];
    }
}

void  reverse(int a, int b, char str[])
{
    int left = a;
    int right = b;
    while(left < right)
    {
        swap(str[left],str[right]);
        left++;
        right--;
    }
}

int main()
{
    char str[1000];
    scanf("%s",str);
    int q, a, b;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        string order;
        cin >> order >> a >> b;
        if (order == "replace") replace(a, b, str);
        if (order == "reverse") reverse(a, b, str);       
        if (order == "print") print(a, b, str);
    }
    return 0;
}