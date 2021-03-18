#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 4000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;

// 挿入ソート (整列してある配列に追加要素を適切な場所に挿入する)

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++)
    {
        for (int i = 0; i < n; i++)
        {
            cout << a[i];
            if (i == n - 1) cout << endl;
            else    cout << " ";
        }

        int v = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > v)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = v;
    }
    return 0;
}