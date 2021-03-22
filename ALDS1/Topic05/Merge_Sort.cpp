#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10

/*  マージソート
    1. 指定されたn個の要素を含む部分配列をそれぞれ n / 2 個の要素を含む２つの部分配列に「分割」する。(Divide)
    2. その２つの部分配列をそれぞれ mergeSort でソートする。（Solve)
    3. 得られた２つのソート済み部分配列を merge により「統合」する。（Conquer）

    計算量は O(n log n)
*/

int cnt = 0;

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
        }
        cnt++;
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

    for (int i = 0; i < n; i++) 
    {
        cout << a[i];
        if (i == n - 1) cout << endl;
        else    cout << " ";
    }
    cout << cnt << endl;
    return 0;
}