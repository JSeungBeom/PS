#include <bits/stdc++.h>

using namespace std;

int n, m, k;
int note[50][50];
int stick[20][20];
int r, c;

bool chk(int x, int y) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (note[x + i][y + j] == 1 && stick[i][j] == 1)
				return 0;
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if(stick[i][j])
				note[x + i][y + j] = stick[i][j];
		}
	}

	return 1;
}

void rotate() {
	int tmp[20][20];

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			tmp[i][j] = stick[i][j];
		}
	}

	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++) {
			stick[i][j] = tmp[r - 1 - j][i];
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
				cin >> stick[i][j];
			}
		}
		
		for(int rot = 0; rot < 4; rot++){
			bool flag = 0;
			for (int i = 0; i <= n - r; i++) {
				if (flag) break;
				for (int j = 0; j <= m - c; j++) {
					if (chk(i, j)) {
						flag = 1;
						break;
					}
				}
			}

			if (flag) break;
			rotate();
		}

	}

	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (note[i][j]) ans++;
		}
	}

	cout << ans;
}