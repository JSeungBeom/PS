#include <bits/stdc++.h>

using namespace std;

int n;

int board[20][20];
bool vis[20][20];
int dx[3] = { 0, 1, 1 };
int dy[3] = { 1, 0, 1 };
int ans;

void dfs(int x, int y, int dir) {

	if (x == n  && y == n) {
		ans++;
		return;
	}

	vis[x][y] = 1;

	for (int i = 0; i < 3; i++) {
		if (dir == 0 && i == 1) continue;
		else if (dir == 1 && i == 0) continue;
		else {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx > n || ny < 0 || ny > n) continue;

			if (i < 2) {
				if (!board[nx][ny] && !vis[nx][ny]) {
					dfs(nx, ny, i);
					vis[nx][ny] = 0;
				}
			}
			else {
				if (!board[nx][ny] && !board[nx - 1][ny] &&
					!board[nx][ny - 1] && !vis[nx][ny])
					dfs(nx, ny, i);
					vis[nx][ny] = 0;
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
		}
	}
	
	dfs(1, 2, 0);

	cout << ans;
}