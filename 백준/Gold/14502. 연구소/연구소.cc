#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int board1[10][10];


int n, m;
int mx = -0x7f7f7f7f;

int wall[100];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board1[i][j];
		}
	}

	int idx = n * m;

	fill(wall + (idx - 3), wall + idx, 1);

	do {

		int board2[10][10];

		queue<pair<int, int>> Q = {};
		bool vis[10][10] = {};
		int cnt = 0;
		int ans = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				board2[i][j] = board1[i][j];
				if (board1[i][j] == 2) {
					Q.push({ i, j });
					vis[i][j] = 1;
				}
			}
		}

		for (int i = 0; i < n * m; i++) {
			int x = i / m;
			int y = i % m;

			if (wall[i] == 1) {
				if (board1[x][y] == 0){
					board2[x][y] = 1;
					cnt++;
				}
			}

		}

		if (cnt != 3) {
			continue;
		}

		while (!Q.empty()) {
			auto cur = Q.front(); Q.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];

				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (vis[nx][ny] || board2[nx][ny] != 0) continue;

				vis[nx][ny] = 1;
				Q.push({ nx, ny });
				board2[nx][ny] = 2;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board2[i][j] == 0)
				ans++;
			}
		}
		mx = max(mx, ans);

	} while (next_permutation(wall, wall + idx));

	cout << mx;
}