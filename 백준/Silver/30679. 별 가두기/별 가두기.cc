#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n, m;
int board[105][105];
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int vis[105][105];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}


	int cnt = 0;
	vector<int> ans;

	for (int i = 0; i < n; i++) {
		pair<int, int> cur = { i, 0 };
		vis[cur.X][cur.Y]++;

		int nx = cur.X;
		int ny = cur.Y;
		int dir = 0;
		int sum = 0;

		while (true) {
			nx += (dx[dir] * board[nx][ny]);
			ny += (dy[dir] * board[nx][ny]);

			dir = (dir + 1) % 4;
			sum++;

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) break;

			if (sum > (4 * n * m)) {
				cnt++;
				ans.push_back(cur.X);
				break;
			}
		}


	}

	cout << cnt << '\n';

	for (auto e : ans)
		cout << e + 1 << ' ';
}
