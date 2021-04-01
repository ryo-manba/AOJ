#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

/*  2 つのソート済み範囲の積集合を得る
    最大で 2 * ((last1 - first1) + (last2 - first2)) - 1 回の比較を行う
*/

int main()
{
    int n, m;
    multiset<int> st1,st2;
    vector<int> result;
    cin >> n;
    for (int i = 0; i < n; i++) 
    {
        int a;
        cin >> a;
        st1.insert(a);
    }
    cin >> m;
    for (int i = 0; i < m; i++) 
    {
        int b;
        cin >> b;
        st2.insert(b);
    }

    set_intersection(begin(st1), end(st1), begin(st2), end(st2), inserter(result, end(result)));
    for (auto s : result)
    {
        cout << s << endl;
    }   
    return 0;
}