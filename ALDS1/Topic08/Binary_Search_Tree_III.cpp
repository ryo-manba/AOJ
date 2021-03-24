#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10

/*  二分探索木
    deleteの追加
    ノードの削除はポインタを繋ぎかえることによって行う。
    1. 子を持たない
    2. 子が1つ
    3. 子が2つ
    これらパターンによって変える
*/

struct Node {
    Node() {
        parent = left = right = 0;
        key = 0;
    }
    int key;
    Node *parent;
    Node *left, *right;
};

Node *NIL;      // ノードが存在しない場合
Node *root;     // 根

Node* next_node(Node *node)
{
    Node *x;
    if (node->right != NIL)
    {
         x = node->right;
         while (x->left != NIL)
            x = x->left;
    }
    else
    {
        x = node;
        while (x->parent != NIL && x == x->parent->right)
            x = x->parent;
        x = x->parent;
    }
    return x;
}

void delete_node(int key)
{
    Node *x, *y, *z;

    z = root;
    // keyの位置まで進める
    while (z->key != key)
    {
        if (z->key > key) 
            z = z->left;
        else
            z = z->right;
    }

    if (z->left == NIL || z->right == NIL)
        y = z;
    else
        y = next_node(z);
    
    if (y->left != NIL)
        x = y->left;
    else
        x = y->right;

    // ポインタを繋ぎ変える
    if (x != NIL)
        x->parent = y->parent;
    if (y->parent == NIL)
        root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;

    // 子が2つの場合 yのキーをzに移す
    if (z != y)
        z->key = y->key;

    delete y; // メモリを解放
}

bool find(int z)
{
    Node *f = root;
    while (f != NIL)
    {
        if (z == f->key)
            return true;
        if (z < f->key)     // 大きい場合左へ
            f = f->left;
        else
            f = f->right;   // 小さい場合右へ
    }
    return false;
}

void insert(int key)
{
    Node *x, *y, *z;

    z = new Node;   // メモリの確保(コンストラクタにより初期化される)
    z->key = key;

    y = NIL;
    x = root;

    // rootから適切な位置まで二分木をたどる
    while (x != NIL)
    {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    // 新しい要素を配置する場所
    z->parent = y;
    if (y == NIL)
        root = z;   // もともと木が存在しない場合      
    else if (z->key < y->key)
        y->left = z;
    else
        y->right = z;
}

// 先行順巡回
void pre(Node* node)
{
    if (node == NIL) return;
    cout << " " << node->key;
    if (node->left != NIL) pre(node->left);
    if (node->right != NIL) pre(node->right);
}

// 中間順巡回
void in(Node* node)
{
    if (node == NIL) return;
    if (node->left != NIL) in(node->left);
    cout << " " << node->key;
    if (node->right != NIL) in(node->right);
}

void print()
{
    in(root);
    cout << endl;
    pre(root);
    cout << endl;
}

int main()
{
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        string s;
        int key;
        cin >> s;
        if (s == "insert")
        {
            cin >> key;
            insert(key);
        }
        if (s == "find")
        {
            cin >> key;
            if (find(key)) 
                cout << "yes" << endl;
            else    
                cout << "no" << endl;
        }
        if (s == "delete")
        {
            cin >> key;
            delete_node(key);
        }
        if (s == "print")
            print();       
    }
    return 0;
}