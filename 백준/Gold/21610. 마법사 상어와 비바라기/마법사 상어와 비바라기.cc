#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n, m;

int board[52][52];
bool cloud[52][52];
bool increased[52][52];

int dx[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };

void step1(int s, int dir) {
	bool tmp[52][52] = { 0, };

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int nx = i;
			int ny = j;
			for (int k = 0; k < s; k++) {
				nx += dx[dir  -1];
				ny += dy[dir - 1];
				if (nx < 1)
					nx = n;
				if (ny < 1)
					ny = n;
				if (nx > n)
					nx = 1;
				if (ny > n)
					ny = 1;
			}
			tmp[nx][ny] = cloud[i][j];

		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cloud[i][j] = tmp[i][j];
		}
	}
}

void step2() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (cloud[i][j]) {
				board[i][j]++;
			}
		}
	}
}

void step3() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (cloud[i][j]) {
				increased[i][j] = 1;
				cloud[i][j] = 0;
			}
		}
	}
}

void step4() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (increased[i][j]) {
				for (int dir = 1; dir < 8; dir += 2) {
					int nx = i + dx[dir];
					int ny = j + dy[dir];

					if (nx < 1 || nx > n || ny < 1 || ny > n) continue;

					if (board[nx][ny])
						board[i][j]++;
				}
			}
		}
	}
}

void step5() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (board[i][j] >= 2 && !increased[i][j]) {
				cloud[i][j] = 1;
				board[i][j] -= 2;
			}

			increased[i][j] = 0;
		}
	}
}

int cnt() {
	int ans = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans += board[i][j];
		}
	}

	return ans;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
		}
	}

	int s, d;

	cloud[n][1] = 1;
	cloud[n][2] = 1;
	cloud[n - 1][1] = 1;
	cloud[n - 1][2] = 1;

	for (int i = 0; i < m; i++) {
		cin >> d >> s;

		step1(s, d);
		step2();
		step3();
		step4();
		step5();
	}

	cout << cnt();
}
