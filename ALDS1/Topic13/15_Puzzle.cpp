#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
struct fast_ios { fast_ios(){ cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(20); }; } fast_ios_;
const int INF = (int)1e9;
const ll INFL = (ll)1e18;
const int MOD = 1e9 + 7;
const double EPS = 1e-10;
int dx[]={0, 0, -1, 1};
int dy[]={1, -1, 0, 0};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int t[4][4];
int	limit;

int	getHeuri()
{
	int	res = 0, a;
	rep(i,4) {
		rep(j,4) {
			if (t[i][j] == 0)
				continue;
			a = t[i][j] - 1;
			res += abs(a / 4 - i) + abs(a % 4 - j);
		}
	}
	return (res);
}

bool	check(int depth, int prev, int py, int px)
{
	int heuri = getHeuri();
	if (heuri + depth > limit)
		return false;
	if (heuri == 0)
		return true;
	rep(i,4) {
		if (abs(i - prev) == 2)
			continue;
		int	ny = py + dy[i], nx = px + dx[i];
		if (ny < 0 || nx < 0)
			continue;
		if (ny >= 4 || nx >= 4)
			continue;
		swap(t[ny][nx], t[py][px]);
		if (check(depth + 1, i, ny, nx))
			return true;
		swap(t[ny][nx], t[py][px]);
	}
	return (false);
}

void	solve(int py, int px)
{
	for (limit = 0;; limit++) {
		if (check(0, 99, py, px)) {
			cout << limit << endl;
			return;
		}
	}
}

int main()
{
	int py, px;
	rep(i,4) {
		rep(j,4) {
			cin >> t[i][j];
			if (t[i][j] == 0) {
				py = i;
				px = j;
			}
		}
	}
	solve(py, px);
	return 0;
}
