#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7;
#define EPS = 1e-10;

const int SIZE = 1000;

int main()
{
    int n, ans = 0;
    int A[SIZE], B[SIZE];
    bool visited[SIZE] = {false};
    map<int, int> mp;
    cin >> n;
    // 配列を2つ作る
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        mp[A[i]] = i;
        B[i] = A[i];
    } 
    // 一つだけソートする
    sort(B, B + n);
    for (int i = 0; i < n; i++)
    {
        int index = i;
        int x = 0, y = 0;
        int mini = INF;
        while (!visited[index])
        {
            mini = min(mini, A[index]); y += A[index];
            x++;
            visited[index] = true;
            index = mp[B[index]];
        }

        // 各サイクルのコストは、そのサイクルの最小元を除いた各要素の重さと、運び屋のコストの和
        if (x >= 2) ans += min(y + mini + B[0] * (x + 1), y + mini * (x - 2));
    }
    cout << ans << endl;
    return 0;
}