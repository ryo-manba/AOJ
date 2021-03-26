#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10

/*  ヒープソート
    1. 未整列データを木構造にする。
    2. 木構造の根（ルート）が最大値または最小値になるように並び替えを行う。
    3. 並び替えが完了した木構造の根（ルート）の値を整列済みデータとする。
    4. 1～3を繰り返して、全て整列済みデータになったら終了。
*/


// i 番目の頂点を根とする部分木について、ヒープ条件を満たすようにする
// a のうち 0 番目から N - 1 番目までの部分についてのみ考える

void Heapify(vector<int> &a, int i, int N)
{
    int left_child = i * 2 + 1;
    if (left_child >= N) return;

    // 子供同士を比較
    if (left_child + 1 < N && a[left_child + 1] > a[left_child])
        ++left_child;
    if (a[left_child] <= a[i]) return;

    swap(a[i], a[left_child]);

    // 再帰的に
    Heapify(a, left_child, N);
}

void HeapSort(vector<int> &a)
{
    int N = (int)a.size();
    // 全体をヒープにする
    for (int i = N / 2 - 1; i >= 0; i--)
        Heapify(a, i, N);
    
    // ヒープから 1 個 1 個最大値を pop する
    for (int i = N - 1; i > 0; i--)
    {
        swap(a[0], a[i]);   // ヒープの最大値を左詰め
        Heapify(a, 0, i);   // ヒープサイズを i に
    }
}

// スワップの回数が最大になるように並び替える
void inverse_HeapSort(vector<int> &a)
{
    for(int i = 2; i < (int)a.size(); i++)
    {
      swap(a[0], a[i - 1]);
      int index = i;
      while(index > 1)
      {
        swap(a[index - 1], a[index / 2 - 1]);
        index /= 2;
      }
    }
    int j = a.size();
    swap(a[0], a[j - 1]);
    return;
}
  
int main()
{
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    HeapSort(a);
    inverse_HeapSort(a);
    for (int i = 0; i < N; i++)
    {
        if (i) cout << " ";
        cout << a[i];
    }
    cout << endl;
}