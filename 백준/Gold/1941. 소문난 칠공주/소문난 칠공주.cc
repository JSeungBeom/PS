#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

char board[30][30];
bool candi[25];
int ans;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> board[i][j];
		}
	}

	fill(candi + 7, candi + 25, 1); // 25C7

	do {
		queue<pair<int, int>>Q;

		int dasom = 0, adj = 0;
		bool isp[5][5] = {}, vis[5][5] = {};
		for (int i = 0; i < 25; i++) {
			if (!candi[i]) {
				int x = i / 5;
				int y = i % 5;
				isp[x][y] = 1;
				if (Q.empty()) {
					Q.push({ x, y });
					vis[x][y] = 1;
				}
			}
		}

		while (!Q.empty()) {
			int x, y;
			tie(x, y) = Q.front(); Q.pop();
			adj++;
			if (board[x][y] == 'S') {
				dasom++;
			}
			for (int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || vis[nx][ny] || !isp[nx][ny])
					continue;
				Q.push({ nx, ny });
				vis[nx][ny] = 1;
			}
		}

		if (adj >= 7 && dasom >= 4) {
			ans++;
		}
	} while (next_permutation(candi, candi + 25));

	cout << ans;
}