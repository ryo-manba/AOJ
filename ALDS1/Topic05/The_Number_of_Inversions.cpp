#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10

/* 反転数 (転倒数とも呼ぶ。もとの配列において左側のほうが値が大きいようなペアの数。
        　バブルソートを行った交換回数と等しい ex){3, 1, 5, 4, 2}の転倒数は 5
*/

ll cnt = 0;

// そのままバブルソートするとTLEするのでマージソートで短縮している
void merge(int *a, int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;
    // 2つに分割する
    vector<int> L(n1 + 1), R(n2 + 1);
    for (int i = 0; i < n1; i++) L[i] = a[left + i];
    for (int i = 0; i < n2; i++) R[i] = a[mid + i];

    L[n1] = INF;
    R[n2] = INF;
    int i = 0, j = 0;
    for (int k = left; k < right; k++)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
            // Lのうちまだmergeされていない要素の個数を足す
            cnt += n1 - i;
        }
    }
}

void mergeSort(int *a, int left, int right)
{
    if (left + 1 < right)
    {
        int mid = (left + right) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid, right);
        merge(a, left, mid, right);
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    mergeSort(a, 0, n);
    cout << cnt << endl;
    return 0;
}