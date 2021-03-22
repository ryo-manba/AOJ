#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10

// フィボナッチ数列 (1つ前と2つ前の数を足して新しい数を計算する)

// メモ用
vector<ll> memo(50, -1);

ll fib(int n)
{
    // 値をメモすることで処理を減らす
    if (memo[n] != -1) return memo[n];
    return memo[n] = fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;
    cin >> n;
    memo[0] = 1;
    memo[1] = 1;
    cout << fib(n) << endl;
    return 0;
}