#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int r, c;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

char board[25][25];
bool vis[26];
int mx;

void dfs(int x, int y, int dist) {
	
	mx = max(mx, dist);

	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
		if (vis[board[nx][ny] - 'A']) continue;

		vis[board[nx][ny] - 'A'] = 1;
		dfs(nx, ny, dist + 1);
		vis[board[nx][ny] - 'A'] = 0;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
		}
	}
	
	vis[board[0][0] - 'A'] = 1;
	dfs(0, 0, 1);

	cout << mx;
}