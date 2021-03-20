#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7;
#define EPS = 1e-10;

// コッホ曲線 (直線を3等分し、真ん中の部分で正三角形を作り下の線を消す)

struct Point {
    double x;
    double y;
};

void print(Point p)
{
    printf("%.7f %.7f\n", p.x, p.y);
}

// コッホ曲線を描くメソッド
void koch(int d, Point p, Point q)
{
    if (d == 0) return;

    // メソッド内部で使用する3点
    Point a, b, c;
    a.x = (2 * p.x + q.x) / 3.0;
    a.y = (2 * p.y + q.y) / 3.0;
    c.x = (p.x + 2 * q.x) / 3.0;
    c.y = (p.y + 2 * q.y) / 3.0;

    double angle = M_PI * 60 / 180.0;
    b.x = (c.x - a. x) * cos(angle) - (c.y - a.y) * sin(angle) + a.x;
    b.y = (c.x - a. x) * sin(angle) + (c.y - a.y) * cos(angle) + a.y;

    koch(d - 1, p, a);
    print(a);
    koch(d - 1, a, b);
    print(b);
    koch(d - 1, b, c);
    print(c);
    koch(d - 1, c, q);
}

int main()
{
    int n;
    cin >> n;

    Point p1, p2;
    // 端点がp1 = (0, 0)から開始, p2 = (100, 0)で終える線分
    p1.x = 0; p1.y = 0;
    p2.x = 100; p2.y = 0;

    print(p1);
    koch(n, p1, p2);
    print(p2);
    return 0;
}