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
    ll a, b;
    cin >> a >> b;
    bitset<32> A(a);
    bitset<32> B(b);
    cout << (A & B) << endl;
    cout << (A | B) << endl;
    cout << (A ^ B) << endl;
    return 0;
}