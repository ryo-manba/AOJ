#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10

/*  木の巡回
    ある木に属する全てのノードを順番に１回づつ訪問するアルゴリズム。
    1. 先行順巡回(Pre-order)  根→左部分木→右部分木
    2. 中間順巡回(In-order)   左部分木→根→右部分木
    3. 後行順巡回(Post-order) 左部分木→右部分木→根
*/


struct Node {
    Node() {
        left = right = parent = -1;
    }
    int left, right, parent;
};

/* 出力する位置を変えるだけで処理自体は同じ　*/

//  root->left->right の順
void pre(Node order[], int id)
{
    cout << " " << id;
    if (order[id].left != -1) pre(order, order[id].left);
    if (order[id].right != -1) pre(order, order[id].right);
}

//  left->root->right の順
void in(Node order[], int id)
{
    if (order[id].left != -1) in(order, order[id].left);
    cout << " " << id;
    if (order[id].right != -1) in(order, order[id].right);
}

//  left->right->root の順
void post(Node order[], int id)
{
    if (order[id].left != -1) post(order, order[id].left);
    if (order[id].right != -1) post(order, order[id].right);
    cout << " " << id;
}


int main()
{
    int n, id, left_id, right_id, root_id;
    cin >> n;
    Node order[n];
    for (int i = 0; i < n; i++)
    {   
        cin >> id >> left_id >> right_id;

        // 左右の子を割り振る
        if (left_id != -1)
        {
            order[id].left = left_id;
            order[left_id].parent = id;
        }
        if (right_id != -1)
        {
            order[id].right = right_id;
            order[right_id].parent = id;
        }
    }

    // root を調べる
    for (root_id = 0; root_id < n; root_id++)
    {
        if (order[root_id].parent == -1) break;
    }

    cout << "Preorder" << endl;
    pre(order, root_id);
    cout << endl;

    cout << "Inorder" << endl;
    in(order, root_id);
    cout << endl;

    cout << "Postorder" << endl;
    post(order, root_id);
    cout << endl;
    return 0;
}