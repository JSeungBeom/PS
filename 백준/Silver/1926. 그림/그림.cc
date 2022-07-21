#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[505][505];
bool vis[505][505];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int n, m;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	int cnt = 0;
	int max = 0;
	int count = 0;

	queue<pair<int, int>> Q;

	for (int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++){
			if (board[i][j] != 1 || vis[i][j]) continue;
			Q.push({ i, j });
			vis[i][j] = true;
			count++;
			cnt = 0;

			while (!Q.empty()) {
				pair<int, int> cur = Q.front(); Q.pop();
				cnt++;
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (vis[nx][ny] || board[nx][ny] != 1) continue;

					vis[nx][ny] = true;
					Q.push({ nx, ny });
				}
				if (cnt > max) {
					max = cnt;
				}
			}
		}
	}

	cout << count << "\n" << max;
}