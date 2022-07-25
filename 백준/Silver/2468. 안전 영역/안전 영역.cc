#include <bits/stdc++.h>	

using namespace std;

#define X first
#define Y second

int board[102][102];

int dx[4] = { 1, 0, -1 ,0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	int n;
	cin >> n;

	int max = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] > max) {
				max = board[i][j];
			}
		}
	}

	int maxcnt = 0;

	for (int i = 0; i <= max; i++) {
		bool vis[102][102] = {};
		queue<pair<int, int>> Q = {};
		int cnt = 0;

		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (board[j][k] <= i || vis[j][k]) continue;

				cnt++;
				Q.push({ j, k });
				vis[j][k] = 1;

				while (!Q.empty()) {
					auto cur = Q.front(); Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];

						if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if (board[nx][ny] <= i || vis[nx][ny]) continue;

						vis[nx][ny] = 1;
						Q.push({ nx, ny });
					}
				}
			}
		}

		if (cnt > maxcnt) {
			maxcnt = cnt;
		}
	}
	cout << maxcnt;
}