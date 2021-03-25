#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10

/*  Treap (Tree(木構造)と Heap(ヒープ)を組み合わせたもの)
    乱択アルゴリズムを用いた平衡二分探索木
    乱数を使って木の平衡を保つ。
    ペア(X, Y)を格納するデータ構造でXに関しては二分探索木、Yに関しては最大値ヒープになっているもの。
    Xはkey, Yはpriorityと呼ばれる。
*/

struct Node {
    Node() {
        right = left = parent = NULL;
    }
    Node(int a, int b): key(a), priority(b) {left = right = parent = NULL;};
    int key;       
    int priority;
    struct Node *parent, *right, *left;
};

Node *root;

Node *rightRotate(Node *node)
{
    Node *p = node->left;
    node->left = p->right;
    p->right = node;
    return p;
}

Node *leftRotate(Node *node)
{
    Node *p = node->right;
    node->right = p->left;
    p->left = node;
    return p;
}

Node *insert(Node *node, int key, int priority)
{
    if (node == NULL)
        return new Node(key, priority);     // 葉に到達したら新しい節点を生成して返す
    if (node->key == key)
        return node;
    if (node->key > key)
    {
        node->left = insert(node->left, key, priority);
        if (node->priority < node->left->priority)
            node = rightRotate(node);       // 左の子の方が優先度が高い場合は右回転
    }
    else
    {
        node->right = insert(node->right, key, priority);
        if (node->priority < node->right->priority)
            node = leftRotate(node);        // 右の子の方が優先度が高い場合は左回転
    }
    return node;
}

Node *_delete(Node *node, int key);
Node *Delete(Node *node, int key)
{
    if (node == NULL)
        return NULL;
    // 削除対象を検索
    if (node->key > key)
        node->left = Delete(node->left,key);
    else if (node->key < key)
        node->right = Delete(node->right, key);
    else
        return _delete(node, key);
    return node;
}

Node *_delete(Node *node, int key)
{
    if (node->left == NULL && node->right == NULL)  // 葉の場合
        return NULL;
    else if (node->left == NULL)
        node = leftRotate(node);                    // 右の子のみを持つ場合は左回転
    else if (node->right == NULL)
        node = rightRotate(node);                   // 左の子のみを持つ場合は右回転
    else
    {                                               // 両方を持つ場合は優先が高い方を持ち上げる
        if (node->left->priority > node->right->priority)
            node = rightRotate(node);
        else
            node = leftRotate(node);
    }
    return Delete(node, key);
}

bool find(int key)
{
    Node *node = root;
    while(node)
    {
        if (node->key == key)
            return 1;
        if (node->key < key)
            node = node->right;
        else
            node = node->left;
    }
    return 0;
}

// 先行順巡回
void pre(Node* node)
{
    if (node == NULL) return;
    cout << " " << node->key;
    if (node->left != NULL) pre(node->left);
    if (node->right != NULL) pre(node->right);
}

// 中間順巡回
void in(Node* node)
{
    if (node == NULL) return;
    if (node->left != NULL) in(node->left);
    cout << " " << node->key;
    if (node->right != NULL) in(node->right);
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
    int n, k, node;
    string order;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> order;
        if (order == "insert")
        {
            cin >> k >> node;
            root = insert(root, k, node);
        }
        if (order == "find")
        {
            cin >> k;
            if (find(k))
                cout << "yes" << endl;
            else
                cout << "no" << endl;
        }
        if (order == "delete")
        {
            cin >> k;
            root = Delete(root, k);
        }
        if (order == "print")
            print();
    }
    return 0;
}