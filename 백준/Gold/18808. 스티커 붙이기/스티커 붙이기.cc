#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int note[50][50];
int board[12][12];
int cnt = 0;
int r, c;

bool pastable(int x, int y) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (note[x + i][y + j] == 1 && board[i][j] == 1)
				return false;
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (board[i][j] == 1) {
				note[x + i][y + j] = 1;
			}
		}
	}

	return true;
}

void spin() {
	int tmp[12][12];
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			tmp[i][j] = board[i][j];
		}
	}
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++) {
			board[i][j] = tmp[r - 1 - j][i];
		}
	}
	
	swap(r, c);
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k;
	for (int a = 0; a < k; a++) {
		cin >> r >> c;

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> board[i][j];
			}
		}

		for (int rot = 0; rot < 4; rot++) {
			bool flag = false;
			for (int x = 0; x <= n - r; x++) {
				if (flag) break;
				for (int y = 0; y <= m - c; y++) {
					if (pastable(x, y)) {
						flag = true;
						break;
					}
				}
			}

			if (flag)
				break;
			spin();
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cnt += note[i][j] == 1;
		}
	}

	cout << cnt;
}