#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10

/*  二分木
    1つの親に対して最大2つまでの子を持つ、枝分かれして広がっていく構造。
    典型的には2つの子はそれぞれ「左」「右」と呼ばれる。

    height -> 任意の節点から葉までの経路の長さの最大値、高さ
    degree -> 任意の節点の子の数、次数（孫は数えない)
    sibling -> 兄弟
*/

struct Node {

    // 呼び出す時に初期化
    Node() {
        brother = parent = -1;
        height = depth = num_of_children = 0;
    }
    int parent, brother;
    int depth, height;
    int num_of_children;
    vector<int> children;
};

// 深さを調べる
void calcDepth(Node nodes[], int root_id)
{
    for (int i = 0; i < nodes[root_id].num_of_children; i++)
    {
        nodes[nodes[root_id].children[i]].depth = nodes[root_id].depth + 1;
        calcDepth(nodes, nodes[root_id].children[i]);
    }
}

// 高さを調べる
void calcHeight(Node nodes[], int height, int parent)
{
    nodes[parent].height = max(nodes[parent].height, height + 1);
    if (nodes[parent].parent != -1)
        calcHeight(nodes, height + 1, nodes[parent].parent);
}

int main()
{
    int n, id;
    int root_id, right, left;
    cin >> n;
    Node nodes[n];

    for (int i = 0; i < n; i++)
    {
        cin >> id >> left >> right;
        if (left != -1)
        {
            nodes[id].children.push_back(left);
            nodes[id].num_of_children++;
            nodes[left].parent = id;
        }
        if (right != -1)
        {
            nodes[id].children.push_back(right);
            nodes[id].num_of_children++;
            nodes[right].parent = id;
        }
        // 子を持たない場合
        if (left != -1 && right != -1)
        {
            nodes[left].brother = right;
            nodes[right].brother = left;
        }
    }

    for (root_id = 0; root_id < n; root_id++)
    {
        if (nodes[root_id].parent == -1) break;
    }

    if (n > 1)
    {
        calcDepth(nodes, root_id);

        for (int i = 0; i < n; i++) 
        {
            if (nodes[i].num_of_children == 0)
                calcHeight(nodes, 0, nodes[i].parent);
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d,"
                , i, nodes[i].parent, nodes[i].brother, nodes[i].num_of_children, nodes[i].depth, nodes[i].height);
        if (nodes[i].parent == -1)
            cout << " root" << endl;
        else if (nodes[i].num_of_children == 0)
            cout << " leaf" << endl;
        else
            cout << " internal node" << endl;
    }
    return 0;
}