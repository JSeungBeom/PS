#include <bits/stdc++.h>

using namespace std;

int n, m;
int board[502][502];
int dp[502][502];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int dfs(int x, int y) {
	if (x == n - 1 && y == m - 1) return 1;
	if (dp[x][y] != -1) return dp[x][y];
	dp[x][y] = 0;

	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

		if (board[x][y] > board[nx][ny]) {
			dp[x][y] += dfs(nx, ny);
		}
	}

	return dp[x][y];

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
	
	for (int i = 0; i < n; i++) {
		fill(dp[i], dp[i] + m, -1);
	}

	cout << dfs(0, 0);
}