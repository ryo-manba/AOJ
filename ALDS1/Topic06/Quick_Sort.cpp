#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7;
#define EPS = 1e-10;

/*  クイックソート
    partition により、対象の部分配列を前後２つの部分配列へ分割する。
    左、右それぞれを再帰的に解く。
    一般的に最も高速なソートアルゴリズム(最悪の場合 O(n^2))
    データの並びによってはオーバーフローの可能性もある
*/

// トランプの柄と数字
struct Card {
    int num, id;
    char pattern;
};

int partition(Card *a, int p, int r)
{
    Card x = a[r];
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (a[j].num <= x.num)
        {   
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}

void quicksort(Card *a, int p, int r)
{
    if (p < r)
    {
        int q = partition(a, p, r);
        quicksort(a, p, q - 1);
        quicksort(a, q + 1, r);
    }
}

// 正しくソートが出来ているか確認する
void check(Card *a, int n)
{
    for (int i = 1; i < n; i++)
    {
        if (a[i - 1].num < a[i].num) continue;
        if (a[i - 1].id < a[i].id) continue;
        cout << "Not stable" << endl;
        return;
    }
    cout << "Stable" << endl;
}

int main()
{
    int n;
    Card a[100000];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].pattern >> a[i].num;
        a[i].id = i;
    }

    quicksort(a, 0, n - 1);
    check(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i].pattern << " " << a[i].num << endl;
    }
    return 0;
}