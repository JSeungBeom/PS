#include <bits/stdc++.h>

#define X first
#define Y second

bool vis[502][502];
int n, m;
int board[502][502];
int dx[4] = { 1, 0 ,-1, 0 };
int dy[4] = { 0, 1, 0, -1 };

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<pair<int, int>> q;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}


	int cnt = 0;
	int mx = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j] || board[i][j] == 0)
				continue;
			cnt++;

			int width = 0;
			vis[i][j] = 1;
			q.push({ i, j });

			while (!q.empty()) {
				pair<int, int> cur = q.front(); q.pop();
				width++;

				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						continue;
					if (vis[nx][ny] || board[nx][ny] == 0)
						continue;
					vis[nx][ny] = 1;
					q.push({ nx, ny });
				}
			}

			mx = max(mx, width);
		}
	}

	cout << cnt << '\n' << mx;
}