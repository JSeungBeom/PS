#include <bits/stdc++.h>	
using namespace std;

#define X first
#define Y second

int board[105][105];
int dist[105][105];
int n, m;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;

	fill(dist[0], dist[105], -1);

	string s;

	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			board[i][j] = s[j] - '0';
		}
	}

	queue<pair<int, int>> Q;
	Q.push({ 0, 0 });
	dist[0][0] = 0;

	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dist[nx][ny] != -1 || board[nx][ny] != 1) continue;

			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			Q.push({ nx, ny });
		}
	}

	cout << dist[n - 1][m - 1] + 1;
}
