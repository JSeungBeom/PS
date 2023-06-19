#include <bits/stdc++.h>
#define X first
#define Y second

#define INF 0x3f3f3f3f

using namespace std;

int n, m;
bool board[103][103];
int d[103][103];
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;

	string s;

	for (int i = 1; i <= n; i++) {
		cin >> s;
		for (int j = 1; j <= m; j++) {
			board[i][j] = s[j - 1] - '0';
		}
	}

	for (int i = 1; i <= n; i++) {
		fill(d[i], d[i] + m + 1, INF);
	}

	d[1][1] = 0;
	pq.push({ 0, 1, 1 });

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		int x, y, cost;
		tie(cost, x, y) = cur;
		if (d[x][y] != cost) continue;
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
			if (d[nx][ny] > board[nx][ny] + cost) {
				d[nx][ny] = board[nx][ny] + cost;
				pq.push({ d[nx][ny], nx, ny });
			}

		}
	}

	cout << d[n][m];
}