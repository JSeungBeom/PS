#include <bits/stdc++.h>

using namespace std;

int n, m, k, r, c;

int board[50][50];
int sticker[15][15];

bool chk(int x, int y) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (board[x + i][y + j] == 1 && sticker[i][j] == 1)
				return 0;
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (sticker[i][j] == 1)
				board[x + i][y + j] = 1;
		}
	}

	return 1;
}

void rotate() {
	int tmp[15][15];

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			tmp[i][j] = sticker[i][j];
		}
	}

	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++) {
			sticker[i][j] = tmp[r - 1 - j][i];
		}
	}

	swap(r, c);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;


	while (k--) {
		cin >> r >> c;

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> sticker[i][j];
			}
		}

		for (int rot = 0; rot < 4; rot++) {
			bool is_paste = 0;
			for (int x = 0; x <= n - r; x++) {
				if (is_paste) break;
				for (int y = 0; y <= m - c; y++) {
					if (chk(x, y)) {
						is_paste = true;
						break;
					}
				}
			}

			if (is_paste) break;
			rotate();
		}

	}

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cnt += board[i][j];
		}
	}

	cout << cnt;

}