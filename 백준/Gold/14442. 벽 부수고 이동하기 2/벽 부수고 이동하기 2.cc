#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#define X first
#define Y second

using namespace std;

int n, m, k;
queue<tuple<int, int, int>> q;
int dist[1005][1005][12];
bool board[1005][1005];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			fill(dist[i][j], dist[i][j] + k + 1, -1);

	string s;

	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			board[i][j] = s[j] - '0';
		}
	}

	dist[0][0][0] = 1;
	q.push({ 0, 0, 0 });

	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		int x, y, broke;
		tie(x, y, broke) = cur;

		if (x == n - 1 && y == m - 1) {
			cout << dist[x][y][broke] << '\n';
			return 0;
		}
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

			if (board[nx][ny] == 0 && dist[nx][ny][broke] < 0) {
				dist[nx][ny][broke] = dist[x][y][broke] + 1;
				q.push({ nx, ny, broke });
			}
			else if (broke < k && board[nx][ny] == 1 && dist[nx][ny][broke + 1] < 0) {
				dist[nx][ny][broke + 1] = dist[x][y][broke] + 1;
				q.push({ nx, ny, broke + 1 });	
			}

		}
	}

	cout << -1;
}

