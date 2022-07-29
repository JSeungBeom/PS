#include <bits/stdc++.h>

using namespace std;

int board[202][202];
int dist[202][202][32];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int dxx[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dyy[8] = { 1, -1, 2, -2, 2, -2, 1, -1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k, n, m;
	cin >> k;
	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fill(dist[i][j], dist[i][j] + 32, -1);
		}
	}
	queue<tuple<int, int, int>> Q;

	Q.push({ 0, 0, 0 });
	dist[0][0][0] = 0;
	
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		int x, y, jumps;
		tie(x, y, jumps) = cur;

		if (jumps < k) {
			// 점프를 한 경우
			for (int dir = 0; dir < 8; dir++) {
				int nx = x + dxx[dir];
				int ny = y + dyy[dir];

				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (dist[nx][ny][jumps + 1] >= 0 || board[nx][ny] == 1) continue;

				dist[nx][ny][jumps + 1] = dist[x][y][jumps] + 1;
				Q.push({ nx, ny, jumps + 1 });
			}
		}
			// 점프를 하지 않은 경우
			for (int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];

				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (dist[nx][ny][jumps] >= 0 || board[nx][ny] == 1) continue;

				Q.push({ nx, ny, jumps });
				dist[nx][ny][jumps] = dist[x][y][jumps] + 1;
			}
	}

	int ans = 1000000;
	for (int i = 0; i <= k; i++) {
		if (dist[n - 1][m - 1][i] != -1) {
			ans = min(ans, dist[n - 1][m - 1][i]);
		}
	}

	if (ans == 1000000) {
		cout << -1;
	}
	else {
		cout << ans;
	}
}