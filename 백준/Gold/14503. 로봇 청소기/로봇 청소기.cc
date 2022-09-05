#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n, m, r, c, d;
int board[52][52];
bool vis[52][52];
int ans;

queue<pair<int, int>> Q;

int dx[4] = {-1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void clean(int x, int y, int dir) {
	Q.push({ x, y });
	vis[x][y] = 1;
	ans++;

	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int i = 0; i < 4; i++) {
			--dir;
			if (dir < 0) dir = 3;
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] == 1 || vis[nx][ny]) continue;

			ans++;
			Q.push({ nx, ny });
			vis[nx][ny] = 1;
			break;
		}

		if (Q.empty()) {
				int back = (dir + 2) % 4;
				if (board[cur.X + dx[back]][cur.Y + dy[back]] != 1)
					Q.push({ cur.X + dx[back], cur.Y + dy[back] });
				else
					break;
		}
	} 
	
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	clean(r, c, d);

	cout << ans;


}