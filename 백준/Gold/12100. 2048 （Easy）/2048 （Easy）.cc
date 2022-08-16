#include <bits/stdc++.h>
using namespace std;

int n;
int board1[25][25];
int board2[25][25];
int mx = 0;

void rotate() {
	int tmp[25][25];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmp[i][j] = board2[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			board2[i][j] = tmp[n-1-j][i];
		}
	}
}
void move(int dir) {
	while (dir--) rotate();
	for (int i = 0; i < n; i++) {
		int tilted[21] = {};
		int idx = 0;
		for (int j = 0; j < n; j++) {
			if (board2[i][j] == 0) continue;
			if (tilted[idx] == 0)
				tilted[idx] = board2[i][j];
			else if (tilted[idx] == board2[i][j])
				tilted[idx++] *= 2;
			else
				tilted[++idx] = board2[i][j];
		}
		for (int j = 0; j < n; j++)
			board2[i][j] = tilted[j];
	}
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board1[i][j];
		}
	}

	for (int i = 0; i < 1024; i++) {
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < n; y++) {
				board2[x][y] = board1[x][y];
			}
		}

		int brute = i;

		for (int j = 0; j < 5; j++) {
			int tmp = brute % 4;
			brute /= 4;

			move(tmp);
		}

		for (int x = 0; x < n; x++) {
			for (int y = 0; y < n; y++) {
				mx = max(mx, board2[x][y]);
			}
		}
	}

	cout << mx;
}