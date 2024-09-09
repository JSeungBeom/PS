#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

const int MX = 0x7fffffff;
int n, m;
int board[10][10];

int dy[3] = { -1 ,0 ,1 };

int dp[10][10];

int solve(int x, int y, int pre) {
	if (x == n) return 0;

	int ret = MX;

	for (int i = 0; i < 3; i++) {
		if (pre == i) continue;
		
		int ny = y + dy[i];

		if (ny < 0 || ny >= m) continue;

		ret = min(ret, solve(x + 1, ny, i) + board[x][y]);
	}

	return ret;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	int ans = MX;

	for (int i = 0; i < m; i++) {
		ans = min(ans, solve(0, i, -1));
	}

	cout << ans;

}