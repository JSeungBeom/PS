#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[8] = { -2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = { 1, -1, 2, -2, 2, -2, 1, -1};

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int dist[302][302] = {};
		int board[302][302] = {};

		for (int i = 0; i < n; i++) {
			fill(dist[i], dist[i] + n, -1);
		}

		queue<pair<int, int>> Q;
		int x, y;
		cin >> x >> y;
		Q.push({ x, y });
		dist[x][y] = 0;

		cin >> x >> y;
		board[x][y] = 1;

		while (!Q.empty()) {
			auto cur = Q.front(); Q.pop();
			if (board[cur.X][cur.Y] == 1) {
				cout << dist[cur.X][cur.Y] << "\n";
				break;
			}
			for (int dir = 0; dir < 8; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if (dist[nx][ny] >= 0) continue;

				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
				Q.push({ nx, ny });
			}
		}
	}
}