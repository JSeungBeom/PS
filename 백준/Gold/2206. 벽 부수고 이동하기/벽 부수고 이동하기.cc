#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[1002][1002];
int dist[1002][1002][2];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			board[i][j] = s[j] - '0';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dist[i][j][0] = -1;
			dist[i][j][1] = -1;
		}
	}

	queue<tuple<int, int, int>> Q;
	dist[0][0][0] = dist[0][0][1] = 1;
	Q.push({ 0, 0, 0});

	while (!Q.empty()) {
		int x, y, broken;
		tie(x, y, broken) = Q.front(); Q.pop();
		// 큐에 거리 순으로 쌓이게 되므로, 가장 빠르게 도달한 경우 출력
		if (x == n - 1 && y == m - 1) {
			cout << dist[x][y][broken];
			return 0;
		}
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] != 1 && dist[nx][ny][broken] == -1) {
				dist[nx][ny][broken] = dist[x][y][broken] + 1;
				Q.push({ nx, ny, broken });
			}

			// 벽을 아직 부수지 않은 경우, 벽을 부수고 가는 case
			if (!broken && board[nx][ny] == 1 && dist[nx][ny][1] == -1) {
				dist[nx][ny][1] = dist[x][y][broken] + 1;
				Q.push({ nx, ny, 1 });
			}
		}
	}

	cout << -1;
	return 0;
}