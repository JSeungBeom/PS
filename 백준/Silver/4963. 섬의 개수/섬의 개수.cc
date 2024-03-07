#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int w, h;
bool board[52][52];
bool vis[52][52];
int dx[8] = { 1, 0, -1, 0, 1, 1, -1, -1 };
int dy[8] = { 0, 1, 0, -1, 1, -1, 1, -1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		cin >> w >> h;
			
		if (w == 0 && h == 0) return 0;

		for (int i = 0; i < h; i++) {
			fill(board[i], board[i] + w, 0);
			fill(vis[i], vis[i] + w, 0);
		}

		queue<pair<int, int>> q;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> board[i][j];
			}
		}

		int cnt = 0;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (vis[i][j] || board[i][j] == 0) continue;

				q.push({ i, j });
				vis[i][j] = 1;
				cnt++;

				while (!q.empty()) {
					auto cur = q.front(); q.pop();

					for (int dir = 0; dir < 8; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];

						if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
						if (vis[nx][ny] || board[nx][ny] == 0) continue;

						q.push({ nx, ny });
						vis[nx][ny] = 1;
					}
				}
			}
		}

		cout << cnt << '\n';
	}
}