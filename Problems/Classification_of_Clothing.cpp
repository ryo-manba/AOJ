#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10

int main()
{   
    // 入力
    int n, h, w;
    cin >> n >> h >> w;
    vector<double> p(h + 2), q(w + 2);
    char c[h + 2][w + 2];
    p[0] = q[0] = 0;
    p[h + 1] = q[w + 1] = 200;

    for (int i = 1; i <= h; i++) cin >> p[i];
    for (int i = 1; i <= w; i++) cin >> q[i];

    for (int i = 1; i <= h + 1; i++) {
        for (int j = 1; j <= w + 1; j++) {
            cin >> c[i][j];
        }
    }

    // grater で昇順にする
    priority_queue<string, vector<string>, greater<string>> s, m, l, x;
    for (int i = 0; i < n; i++) 
    {
        string name;
        double height, weight;
        cin >> name >> height >> weight;

        ll a = upper_bound(p.begin(), p.end(), height) - p.begin();
        ll b = upper_bound(q.begin(), q.end(), weight) - q.begin();
        
        if (c[a][b] == 'S')  s.push(name);
        if (c[a][b] == 'M')  m.push(name);
        if (c[a][b] == 'L')  l.push(name);
        if (c[a][b] == 'X')  x.push(name);
    }

    cout << "S:";
    while (!s.empty())
    {
        cout << " " << s.top();
        s.pop();
    }
    cout << endl;

    cout << "M:";
    while(!m.empty())
    {
        cout << " " << m.top();
        m.pop();
    }
    cout << endl;

    cout << "L:";
    while(!l.empty())
    {
        cout << " " << l.top();
        l.pop();
    }
    cout << endl;

    cout << "X:";
    while(!x.empty())
    {
        cout << " " << x.top();
        x.pop();
    }
    cout << endl;
    return 0;
}