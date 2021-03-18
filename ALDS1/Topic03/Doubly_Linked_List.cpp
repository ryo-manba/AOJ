#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7;
#define EPS = 1e-10;

/* 双方向連結リスト
    要素の挿入や削除は、ノードのリンクをつなぎかえることによって行う。
    リストの各要素が、それぞれ直前と直後の要素の情報を持つようにリンクさせたデータ構造。
    要素の削除や挿入を定数時間で高速に行えるが、要素へのアクセスにO(N)かかる。
*/

struct Node {
    int key;
    Node *next;
    Node *prev;
};

struct List
{   
    // 番兵(特定の値を持たず、先頭の要素と末尾の要素にリンクして両者をつなぐ役割)
    Node* nil;  

    // 初期化
    void init()
    {
        nil = (Node*)malloc(sizeof(Node));  // mallocでNodeの領域を確保
        nil->next = nil;                    // nilが指す前と後ろ、keyを0初期化
        nil->prev = nil;
        nil->key = 0;
    }

    // keyを持つ最初のノードのポインタを返す
    Node* find(int key)
    {
        for (Node* i = nil->next; i != nil; i = i ->next)
        {
            if (i->key == key) return i;
        }
        return nil;
    }

    // 先頭に要素を追加
    void insert(Node *x)
    {
        x->next = nil->next;
        nil->next->prev = x;
        nil->next = x;
        x->prev = nil;
    }

    // 要素を追加する
    void add(int x)
    {
        Node* p = (Node*)malloc(sizeof(Node));  // 追加する要素の領域を確保
        p->key = x;                             // pがxを指すようにする
        insert(p);
    }

    // keyを持つ最初の要素を削除
    void delete_x(int key)
    {
        Node* x = find(key);
        if (x == nil) return;

        // リンクを繋ぎ変える
        x->prev->next = x->next;
        x->next->prev = x->prev;
        free(x);
    }

    // 先頭の要素を削除
    void deleteFirst()
    {
        // リンクを繋ぎ変える
        Node* x = nil->next;
        x->prev->next = x->next;    
        x->next->prev = x->prev;
        free(x);
    }

    // 末尾の要素を削除
    void deleteLast()
    {
        // リンクを繋ぎ変える
        Node* x = nil->prev;
        x->prev->next = x->next;
        x->next->prev = x->prev;
        free(x);
    }

    // リストのすべての要素を表示
    void print_list()
    {
        int flag = 0;
        for (Node* i = nil->next; i != nil; i = i->next)
        {
            if (flag) cout << " ";
            cout << i->key;
            flag = 1;
        }
        cout << endl;
    }
};

int main()
{
    int n, x;
    string s;
    List list;
    cin >> n;
    list.init();
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (s == "insert")
        {
            cin >> x;
            list.add(x);
        }
        if (s == "delete")
        {
            cin >> x;
            list.delete_x(x);
        }
        if (s == "deleteFirst")
        {
            list.deleteFirst();
        }
        if (s == "deleteLast")
        {
            list.deleteLast();
        }
    }
    list.print_list();
    return 0;
}