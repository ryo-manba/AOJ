#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 4000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;

bool isPrime(int n)
{
    if (n == 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    int i = 3;
    while (i * i <= n)
    {
        if (n % i == 0) return false;
        i += 2;
    }
    return true;
}

int main()
{
    int n, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (isPrime(a)) cnt++;
    }
    cout << cnt << endl;
    return 0;
}