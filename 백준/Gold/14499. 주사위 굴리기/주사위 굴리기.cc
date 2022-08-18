#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n, m, x, y, k;

int board[22][22];
int dice[6] = { 0, 0, 0, 0, 0, 0 };
// East : 4, 3, 1, 6, 2, 5
// West : 3, 4, 6, 1, 2, 5
// North : 5, 2, 3, 4, 1, 6
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void roll(int dir) {
	int nx = x + dx[dir];
	int ny = y + dy[dir];

	if (nx < 0 || nx >= n || ny < 0 || ny >= m) return;
	
	switch (dir) {
	case 0:
		swap(dice[0], dice[3]);
		swap(dice[1], dice[2]);
		swap(dice[2], dice[3]);
		break;

	case 1:
		swap(dice[0], dice[2]);
		swap(dice[1], dice[3]);
		swap(dice[2], dice[3]);
		break;

	case 2:
		swap(dice[0], dice[5]);
		swap(dice[1], dice[4]);
		swap(dice[4], dice[5]);
		break;

	case 3:
		swap(dice[0], dice[4]);
		swap(dice[1], dice[5]);
		swap(dice[4], dice[5]);
		break;
	}

	if (board[nx][ny] != 0) {
		dice[1] = board[nx][ny];
		board[nx][ny] = 0;
	}
	else {
		board[nx][ny] = dice[1];
	}

	cout << dice[0] << "\n";
	x = nx;
	y = ny;
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> x >> y >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	while (k--) {
		int d;
		cin >> d;
		roll(d - 1);
	}
}