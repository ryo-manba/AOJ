#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7;
#define EPS = 1e-10;

// 選択ソート (各計算ステップで１つの最小値を「選択」していく)

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int mini = i;
        for (int j = i; j < n; j++)
        {
            if (a[j] < a[mini]) 
            {
                mini = j;               
            }
         }
        if (a[i] != a[mini])
        {
            swap(a[i], a[mini]);
            cnt++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i];
        if (i == n - 1) cout << endl;
        else    cout << " ";
    }
    cout << cnt << endl;
    return 0;
}