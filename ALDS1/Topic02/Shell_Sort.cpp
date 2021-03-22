#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10

/* シェルソート 
(挿入ソートが改良された整列アルゴリズム。
一定の間隔だけ離れた要素のみを対象とした挿入ソートを大きい値から狭めながら繰り返す)*/

int cnt = 0;

void insertionSort(int *a, int n, int g)    // 挿入ソート(間隔gを狭めながらソート)
{
    for (int i = g; i < n; i++)
    {
        int v = a[i];
        int j = i - g;
        while (j >= 0 && a[j] > v)
        {
            a[j + g] = a[j];
            j = j - g;
            cnt++;
        }
        a[j + g] = v;    
    }
}

void shellSort(int *a, int n)
{
    int m = 0;
    int s = 1;
    vector<int> g(20);

    while (n / s > 0)
    {
        s *= 2;
        m++;
    }

    for (int i = 0, t = 1; i < m; i++)
    {
        g[i] = n / t;
        t *= 2;
    }

    for (int i = 0; i < m; i++)
    {
        insertionSort(a, n, g[i]);
    }

    cout << m << endl;
    for (int i = 0; i < m; i++)
    {
        if (i == m - 1)  cout << g[i] << endl;
        else    cout << g[i] << " ";
    }
    cout << cnt << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    int a[1000000];
    for (int i = 0; i < n; i++) cin >> a[i];
    shellSort(a, n);
    return 0;
}