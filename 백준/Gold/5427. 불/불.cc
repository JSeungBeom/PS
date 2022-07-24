#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> m >> n;

		bool flag = 0;
		int board[1002][1002] = {};
		int distF[1002][1002] = {};
		int distS[1002][1002] = {};

		queue<pair<int, int>> Q1 = {};
		queue<pair<int, int>> Q2 = {};

		for (int i = 0; i < n; i++) {
			fill(distF[i], distF[i] + m, -1);
			fill(distS[i], distS[i] + m, -1);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				char c;
				cin >> c;
				if (c == '#') {
					board[i][j] = -1;
				}
				else if (c == '*') {
					Q1.push({ i, j });
					distF[i][j] = 0;
				}
				else if (c == '@') {
					Q2.push({ i, j });
					distS[i][j] = 0;
				}
			}
		}

		while (!Q1.empty()) {
			pair<int, int> cur = Q1.front(); Q1.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];

				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (distF[nx][ny] >= 0 || board[nx][ny] == -1) continue;

				distF[nx][ny] = distF[cur.X][cur.Y] + 1;
				Q1.push({ nx, ny });
			}
		}
		while (!Q2.empty()) {
			pair<int, int> cur = Q2.front(); Q2.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];

				// 범위를 벗어날 시 탈출
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
					flag = 1;
					cout << distS[cur.X][cur.Y] + 1 << "\n";
					while (!Q2.empty())
						Q2.pop();
					break;
				}
				// 방문했거나, 벽인 좌표 
				if (distS[nx][ny] >= 0 || board[nx][ny] == -1) continue;
				if (distF[nx][ny] >= 0 && distF[nx][ny] <= (distS[cur.X][cur.Y] + 1)) continue;

				distS[nx][ny] = distS[cur.X][cur.Y] + 1;
				Q2.push({ nx, ny });
			}
		}

		if (!flag) {
			cout << "IMPOSSIBLE\n";
		}
	}
}