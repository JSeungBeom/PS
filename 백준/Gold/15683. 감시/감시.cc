#include <bits/stdc++.h>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int n, m;

int board1[10][10];
int board2[10][10];
vector<pair<int, int>> cctv;
int mn = 0;

bool OOB(int x, int y) {
	return (x < 0 || x >= n || y < 0 || y >= m);
}

void inspect(int x, int y, int dir) {
	dir %= 4;
	while (true) {
		x += dx[dir];
		y += dy[dir];

		if (OOB(x, y) || board2[x][y] == 6) return;
		if (board2[x][y] != 0) continue;

		board2[x][y] = 7;
	}
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board1[i][j];

			if (board1[i][j] == 0) mn++;
			if (board1[i][j] != 0 && board1[i][j] != 6)
				cctv.push_back({ i, j });
		}
	}

	for (int tmp = 0; tmp < (1 << (2 * cctv.size())); tmp++) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				board2[i][j] = board1[i][j];

		int brute = tmp;
		for (int i = 0; i < cctv.size(); i++) {
			int dir = brute % 4;
			brute /= 4;
			int x, y;
			tie(x, y) = cctv[i];
			if (board1[x][y] == 1) {
				inspect(x, y, dir);
			}
			else if (board1[x][y] == 2) {
				inspect(x, y, dir);
				inspect(x, y, dir + 2);
			}
			else if (board1[x][y] == 3) {
				inspect(x, y, dir);
				inspect(x, y, dir + 1);
			}
			else if (board1[x][y] == 4) {
				inspect(x, y, dir);
				inspect(x, y, dir + 1);
				inspect(x, y, dir + 2);
			}
			else if (board1[x][y] == 5) {
				inspect(x, y, dir);
				inspect(x, y, dir + 1);
				inspect(x, y, dir + 2);
				inspect(x, y, dir + 3);
			}
		}
		
		int cnt = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board2[i][j] == 0)
					cnt++;
			}
		}

		mn = min(mn, cnt);
	}

	cout << mn;
}