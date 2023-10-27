#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n, m;
int board[105][105];
bool vis[105][105];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int t;

bool chk() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j]) return 1;
		}
	}
	
	return 0;
}

void board_init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j])
				board[i][j] = 1;
		}
	}
}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}


	while (chk()) {
		t++;

		for (int i = 0; i < n; i++) {
			fill(vis[i], vis[i] + m, 0);
		}

		board_init();

		queue<pair<int, int>> q;
		q.push({ 0, 0 });

		while (!q.empty()) {
			auto cur = q.front(); q.pop();

			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];

				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (vis[nx][ny]) continue;
				if (board[nx][ny] >= 1) {
					board[nx][ny]++;
					if (board[nx][ny] >= 3) {
						board[nx][ny] = 0;
						vis[nx][ny] = 1;
					}

					continue;
				}

				vis[nx][ny] = 1;
				q.push({ nx, ny });


			}

		}
	}
	cout << t << '\n';
}