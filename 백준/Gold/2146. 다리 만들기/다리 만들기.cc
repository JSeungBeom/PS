#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[102][102];
int dist[102][102];
bool vis[102][102];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	queue<pair<int, int>> Q;
	
	int incre = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 0 || vis[i][j]) continue;

			Q.push({ i, j });
			vis[i][j] = 1;

			while (!Q.empty()) {
				auto cur = Q.front(); Q.pop();
				board[cur.X][cur.Y] = incre;
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (board[nx][ny] == 0 || vis[nx][ny]) continue;

					vis[nx][ny] = 1;
					Q.push({ nx, ny });
				}
			}
			incre++;
		}
	}

	int bridge = 100000;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 0) continue;

			for (int i = 0; i < n; i++) {
				fill(dist[i], dist[i] + n, -1);
			}
			Q.push({ i, j });
			dist[i][j] = 0;
			incre = board[i][j];

			while (!Q.empty()) {
				auto cur = Q.front(); Q.pop();

				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (dist[nx][ny] >= 0 || board[nx][ny] == incre)
						continue;

					if (board[nx][ny] > 0) {
						bridge = min(bridge, dist[cur.X][cur.Y]);
						while (!Q.empty())
							Q.pop();
						break;
					}

					dist[nx][ny] = dist[cur.X][cur.Y] + 1;
					Q.push({ nx, ny });
				}
			}
		}
	}

	cout << bridge;
}