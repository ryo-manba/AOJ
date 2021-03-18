#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7;
#define EPS = 1e-10;

// ラウンドロビンスケジューリング

const int SIZE = 100000;

struct Queue {
    int table[SIZE];
    int head , tail;

    // 初期化
    void init()
    {
        head = tail = 0;
    }

    // 空か調べる
    bool isEmpty()
    {
        return head == tail;
    }

    // 要素を追加
    void enqueue(int x)
    {
        table[tail] = x;
        tail++;
        tail %= SIZE;
    }

    // 要素を取り出す
    int dequeue()
    {
        if (isEmpty()) return 0;
        int res = table[head];
        head++;
        head %= SIZE;
        return res;
    }
};


int main()
{
    int n, num, q;
    Queue queA, queB;
    string table[SIZE];
    cin >> n >> q;
    queA.init();
    queB.init();
    for (int i = 0; i < n; i++)
    {
        cin >> table[i] >> num;
        queA.enqueue(num);
        queB.enqueue(i);
    }

    int now = 0;
    int a, b;
    while (!queA.isEmpty())
    {
        a = queA.dequeue();
        b = queB.dequeue();
        if (a <= q)
        {
            now += a;
            cout << table[b] << " " << now << endl;
        }
        else
        {
            now += q;
            a -= q;
            queA.enqueue(a);
            queB.enqueue(b);
        }
    }
    return 0;
}