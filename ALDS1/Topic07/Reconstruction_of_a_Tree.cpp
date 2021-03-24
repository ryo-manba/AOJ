#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10

/*  木の復元
    先行順巡回(pre)と中間順巡回(in)を行った結果の節点の列から、
    後行順巡回(post)で得られる節点の列を生成する。

    1. ある部分木について、preorderから、節点を見つける
    2. 見つけた節点でinorderを分割し、左部分木、右部分木を作る（実際はinorderの列）
    3. 2で作った左右それぞれの部分木に対応するpreorderの列を生成する。
    4. 2,3で作った左右それぞれのpreorderとinorderの列に対して、1を再帰的に実行する
*/

const int SIZE = 1000;

vector<int> pre(SIZE);
vector<int> in(SIZE);
vector<int> post;

int findroot(int root)
{
    // イテレータの距離を返す
    return distance(in.begin(), find(in.begin(), in.end(), root));
}

void print()
{
    for (int i = 0; i < post.size(); i++)
    {
        if (i)  cout << " ";
        cout << post[i];
    }
    cout << endl;
}

int point = 0;
void reconstruction(int start, int goal)
{
    if (start >= goal) return;

    int root = pre[point++];   // preorderの次の節点
    int m = findroot(root); //  inorderにおけるrootの位置
    reconstruction(start, m);
    reconstruction(m + 1, goal);

    post.push_back(root);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> pre[i];
    for (int i = 0; i < n; i++) cin >> in[i];
    reconstruction(0, n);
    print();
    return 0;
}