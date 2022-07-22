#include <bits/stdc++.h>
using namespace std;

int board[101][101][101];
int dist[101][101][101];
int dx[6] = { 1, 0, 0, -1, 0, 0 };
int dy[6] = { 0, 1, 0, 0, -1, 0 };
int dz[6] = { 0, 0, 1, 0, 0, -1 };
int n, m, h;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n >> h;

	queue<tuple<int, int, int>> Q;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> board[i][j][k];
				if (board[i][j][k] == 0)
					dist[i][j][k] = -1;

				if (board[i][j][k] == 1) 
					Q.push({ i, j, k });
				
			}
		}
	}

	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 6; dir++) {
			int nz = get<0>(cur) + dz[dir];
			int nx = get<1>(cur) + dx[dir];
			int ny = get<2>(cur) + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h)
				continue;
			if (dist[nz][nx][ny] >= 0) continue;

			dist[nz][nx][ny] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
			Q.push({ nz, nx, ny });
		}
	}

	int ans = 0;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (dist[i][j][k] == -1) {
					cout << -1;
					return 0;
				}

				ans = max(ans, dist[i][j][k]);
			}
		}
	}

	cout << ans;
}