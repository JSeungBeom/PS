#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n, m;

int board[1002][1002];
int dist[1002][1002];
queue<pair<int, int>> q;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
void BFS() {
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dist[nx][ny] != 0 || board[nx][ny] == 0) continue;

			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			q.push({ nx, ny });
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;

	int x, y;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) {
				q.push({i, j});
				x = i;
				y = j;
			}
		}
	}

	BFS();
	dist[x][y] = 0;
	

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[i][j] == 0 && board[i][j] == 1) {
				cout << -1 << ' ';
				continue;
			}
			cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}


}