#include <bits/stdc++.h>

using namespace std;

int x, y, d, g, n;

int board[105][105];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void curve(int x, int y, int d, int gen) {
	if (gen > g)
		return;

	int nx = x + dx[d];
	int ny = y + dy[d];

	board[nx][ny] = 1;

	d = (d + 1) % 4;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	while (n--) {
		cin >> x >> y >> d >> g;

		vector<int> v;
		v.push_back(d % 4);
		board[y][x] = 1;

		while (g--) {
			int sz = v.size();

			for (int j = sz - 1; j >= 0; j--) {
				v.push_back((v[j] + 1) % 4);
			}
		}

		for (int i = 0; i < v.size(); i++) {
			int dir = v[i];

			x += dx[dir];
			y += dy[dir];

			board[y][x] = 1;
		}
	}


	int cnt = 0;

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (board[i][j] && board[i + 1][j] &&
				board[i][j + 1] && board[i + 1][j + 1])
				cnt++;
		}
	}

	cout << cnt;


}