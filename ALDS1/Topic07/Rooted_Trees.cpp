#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10

/*  根付き木
    根を持つ木構造。
    根は親を持たない唯一の節点のこと。

    root -> 根 
    leaf -> 葉
    depth -> 木の深さ
    internal node -> 内部節点(葉でない節点)
*/

struct Node {

    // 呼び出す時に初期化
    Node() {
        parent = -1;
        depth = num_of_children = 0;
    }
    int parent;     
    int depth;      
    vector<int> children;   // 子
    int num_of_children;    // 子の数
};

void calcDepth(Node nodes[], int root_id)
{       
    // 子の数だけ loop を回す
    for (int i = 0; i < nodes[root_id].num_of_children; i++)
    {
        // 子の深さに親の深さ + 1 を代入
        nodes[nodes[root_id].children[i]].depth = nodes[root_id].depth + 1;
        // 再帰的に深さを調べていく
        calcDepth(nodes, nodes[root_id].children[i]);
    }
}

int main()
{
    int n, id, k, child_id, root_id;

    // 節点の個数
    cin >> n;
    Node nodes[n];

    // 木構造の入力
    for (int i = 0; i < n; i++) {
        cin >> id >> k;     // id は節点の番号, k は次数
        for (int j = 0; j < k; j++) {
            cin >> child_id;    // 子の節点番号
            nodes[id].children.push_back(child_id);
            nodes[id].num_of_children++;
            nodes[child_id].parent = id;    // 現在のidが親
        }
    }

    // 親がない頂点(根)を調べる
    for (root_id = 0; root_id < n; root_id++) {
        if (nodes[root_id].parent == -1) break;
    }

    // 木の深さを調べる
    calcDepth(nodes, root_id);

    for (int i = 0; i < n; i++) {
        if (nodes[i].parent == -1)  // 親を持たない場合
            printf("node %d: parent = -1, depth = 0, root, ", i);
        else if (nodes[i].num_of_children == 0) // 子を持たない場合
            printf("node %d: parent = %d, depth = %d, leaf, ", i, nodes[i].parent, nodes[i].depth);
        else    // 子を持つ場合
            printf("node %d: parent = %d, depth = %d, internal node, ", i, nodes[i].parent, nodes[i].depth);
        printf("[");
        // 子の数だけ loop を回して出力
        for (int j = 0; j < nodes[i].num_of_children; j++) {
            printf("%d" ,nodes[i].children[j]);
            if (j != nodes[i].num_of_children - 1) cout << ", ";
        }
        printf("]\n");
    }
    return 0;
}