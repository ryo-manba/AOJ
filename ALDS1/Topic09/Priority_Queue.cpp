#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10

/*  優先順位キュー
    キーと値をセットにして保持し、キーを基準としてある一定の優先順位をつける。
    最も高い優先度を持つ要素をキューから取り除き、それを返す。
*/

const int SIZE = 2000100;
int heap_size;

void max_heapify(int *A, int i)
{
    int largest;
    int left = i * 2 + 1;
    int right = i * 2 + 2;

    // 左の子、自分、右の子で値が最大のノードを選ぶ
    if (left < heap_size && A[left] > A[i])
        largest = left;
    else
        largest = i;
    if (right < heap_size && A[right] > A[largest])
        largest = right;

    if (largest != i)   // i の子の方が大きい場合
    {
        swap(A[i], A[largest]); 
        max_heapify(A, largest);    // 再帰的に呼び出す
    }
}

void insert(int *A, int num)
{
    int i = heap_size++;
    A[i] = num;
    while (i && A[(i - 1) / 2] < A[i])
    {
        swap(A[(i - 1) / 2], A[i]);
        i = (i - 1) / 2;
    }
}

int extractMax(int *A)
{
    if (heap_size < 0) return 0;
    int res = A[0];
    A[0] = A[--heap_size];
    max_heapify(A, 0);
    return res;
}

int main()
{
    string s;
    int A[SIZE];
    while (cin >> s)
    {
        if (s == "end") break;
        if (s == "insert")      // 要素を挿入
        {
            int num;
            cin >> num;
            insert(A, num);
        }
        if (s == "extract")     // 最大のキーを出力して削除
            cout << extractMax(A) << endl;
    }
    return 0;
}