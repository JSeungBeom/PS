#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[302][302];


int dx[4] = { 1, 0, -1 , 0 };
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

	int years = 0;

	while (true) {
		years++;
		bool vis1[302][302] = {};
		bool vis2[302][302] = {};
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 0) continue;

				int cnt = 0;
				for (int dir = 0; dir < 4; dir++) {
					int nx = i + dx[dir];
					int ny = j + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (board[nx][ny] != 0 || vis1[nx][ny]) continue;

					vis1[i][j] = 1;
					cnt++;
				}

				board[i][j] -= cnt;
				if (board[i][j] < 0) {
					board[i][j] = 0;
				}
			}
		}

		int mass = 0;

		queue<pair<int, int>> Q = {};
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 0 || vis2[i][j]) continue;

				vis2[i][j] = 1;
				Q.push({ i, j });
				mass++;

				while (!Q.empty()) {
					auto cur = Q.front(); Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];

						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (board[nx][ny] == 0 || vis2[nx][ny]) continue;

						vis2[nx][ny] = 1;
						Q.push({ nx, ny });
					}
				}
			}
		}

		if (mass >= 2) {
			cout << years;
			break;
		}

		int sum = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 0)
					sum++;
			}
		}
		if (sum == n * m) {
			cout << 0;
			break;
		}
	}
}