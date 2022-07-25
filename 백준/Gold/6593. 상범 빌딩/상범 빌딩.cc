#include <bits/stdc++.h>	

using namespace std;


int dx[6] = { 1, 0, 0, -1 ,0, 0 };
int dy[6] = { 0, 1, 0, 0, -1, 0 };
int dz[6] = { 0, 0, 1, 0, 0, -1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while (true) {
		int h, n, m;
		cin >> h >> n >> m;
		if (h == 0 && n == 0 && m == 0)
			return 0;

		char board[32][32][32];
		int dist[32][32][32];

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < n; j++) {
				fill(board[i][j], board[i][j] + m, 0);
				fill(dist[i][j], dist[i][j] + m, 0);
			}
		}
		queue<tuple<int, int, int>> Q;

		bool flag = true;
		string s;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < n; j++) {
	
				cin >> s;
				for (int k = 0; k < m; k++) {
					board[i][j][k] = s[k];

					if (board[i][j][k] == '.') {
						dist[i][j][k] = -1;
					}

					if (board[i][j][k] == 'S') {
						Q.push({ i, j, k });
					}
				}
			}
		}

		while (!Q.empty()) {
			if (!flag)
				break;

			auto cur = Q.front(); Q.pop();
			for (int dir = 0; dir < 6; dir++) {
				int nx = get<1>(cur) + dx[dir];
				int ny = get<2>(cur) + dy[dir];
				int nz = get<0>(cur) + dz[dir];

				// 빌딩을 벗어났을 때
				if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h)
					continue;

				// 막혀있는 칸이거나, 이미 방문한 칸일때
				if (board[nz][nx][ny] == '#' || dist[nz][nx][ny] > 0) continue;
				if (board[nz][nx][ny] == 'E') {
					cout << "Escaped in " << dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1
						<< " minute(s).\n";
					flag = false;
					break;
				}
				dist[nz][nx][ny] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
				Q.push({ nz, nx, ny });
			}
		}

		if (flag) {
			cout << "Trapped!\n";
		}
	}
}