#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10

//  最大ヒープ (根に最大値が来るヒープ)

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

void build_max_heap(int *A)
{
    for (int i = heap_size / 2; i >= 0; i--)
        max_heapify(A, i);
}

int main()
{
    cin >> heap_size;
    int A[heap_size];
    for (int i = 0; i < heap_size; i++) 
        cin >> A[i];
    build_max_heap(A);

    for (int i = 0; i < heap_size; i++)
        cout << " " << A[i];
    cout << endl;
    return 0;
} 