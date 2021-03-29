#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main()
{
    int n;
    cin >> n;
    vector<tuple<ll, ll, char, ll, string>> tup(n);
    for (int i = 0; i < n; i++)
    {
        ll value, weight, data;
        char type;
        string name;
        cin >> value >> weight >> type >> data >> name;
        tup[i] = make_tuple(value, weight, type, data, name);
    }
    sort(tup.begin(), tup.end());
    for (auto t : tup)
    {
        auto a = get<0>(t);
        auto b = get<1>(t);
        auto c = get<2>(t);
        auto d = get<3>(t);
        auto e = get<4>(t);
        cout << a << " " << b << " " << c << " " << d << " " << e << endl;
    }
    return 0;
}