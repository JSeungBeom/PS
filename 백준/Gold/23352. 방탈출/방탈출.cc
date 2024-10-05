#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
using ll = long long;

int n, m;

int dist[52][52];
int board[52][52];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	int ans = 0;
	int mx = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0) continue;

			for (int k = 0; k < n; k++) {
				fill(dist[k], dist[k] + m, -1);
			}

			queue<pair<int, int>> q;

			dist[i][j] = 0;
			q.push({ i, j });
			int st = board[i][j];
			int en = 0;

			while (!q.empty()) {
				auto cur = q.front(); q.pop();

				if (dist[cur.X][cur.Y] > mx) {
					mx = dist[cur.X][cur.Y];
					ans = st + board[cur.X][cur.Y];
				}
				else if (dist[cur.X][cur.Y] == mx) {
					ans = max(ans, st + board[cur.X][cur.Y]);
				}

				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (board[nx][ny] == 0 || dist[nx][ny] >= 0) continue;

					dist[nx][ny] = dist[cur.X][cur.Y] + 1;
					q.push({ nx, ny });
				}
			}
		}
	}
		cout << ans;
}