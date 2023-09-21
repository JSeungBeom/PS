#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int n, l, r;
int board[52][52];
bool vis[52][52];
int ans;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> l >> r;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	while (true) {
		for (int i = 0; i < 52; i++) {
			fill(vis[i], vis[i] + 52, 0);
		}

		queue<pair<int, int>> q;
		bool flag = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				
				if (!vis[i][j]) q.push({ i,j });
				int sum = 0;
				vector<pair<int, int>> tmp;

				while (!q.empty()) {
					auto cur = q.front(); q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];

						if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if (vis[nx][ny]) continue;

						int diff = abs(board[cur.X][cur.Y] - board[nx][ny]);

						if (l <= diff && diff <= r) {
							flag = 1;
							if (!vis[cur.X][cur.Y]) {
								sum += board[cur.X][cur.Y];
								vis[cur.X][cur.Y] = 1;
								tmp.push_back({ cur.X, cur.Y });
							}
							
							if (!vis[nx][ny]) {
								sum += board[nx][ny];
								vis[nx][ny] = 1;
								tmp.push_back({ nx, ny });
								q.push({ nx, ny });
							}
						}
					}
				}

				if (tmp.empty()) continue;

				int div = sum / tmp.size();

				for (auto e : tmp) {
					board[e.X][e.Y] = div;
				}
			}
		}


		if (!flag)
			break;

		ans++;
	}
		
	cout << ans;
}