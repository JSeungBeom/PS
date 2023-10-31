#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int r, c, t;
int board[53][53];
int tmp[53][53];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void spread(int a, int b) {
	int cnt = 0;

	for (int dir = 0; dir < 4; dir++) {
		int nx = a + dx[dir];
		int ny = b + dy[dir];

		if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
		if (board[nx][ny] == -1) continue;

		tmp[nx][ny] += board[a][b] / 5;
		cnt++;
	}

	board[a][b] -= (board[a][b] / 5) * cnt;
}

void add() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			board[i][j] += tmp[i][j];
		}
	}

	for (int i = 0; i < r; i++) {
		fill(tmp[i], tmp[i] + c, 0);
	}
}

void up_conditioning(int a, int b) {
	for (int i = a; i >= 1; i--) {
		board[i][0] = board[i - 1][0];
	}

	board[a][b] = -1;
	for (int i = 0; i < c - 1; i++) {
		board[0][i] = board[0][i + 1];
	}

	for (int i = 0; i < a; i++) {

		if (board[i - 1][c - 1] == -1) board[i][c - 1] = 0;
		else
			board[i][c - 1] = board[i + 1][c - 1];
	}

	for (int i = c - 1; i >= 1; i--) {
		if (board[a][i - 1] == -1) board[a][i] = 0;
		else board[a][i] = board[a][i - 1];
	}

}

void down_conditioning(int a, int b) {
	for (int i = a; i < r - 1; i++) {
		board[i][0] = board[i + 1][0];
	}
	board[a][b] = -1;
	for (int i = 0; i < c - 1; i++) {
		board[r - 1][i] = board[r - 1][i + 1];
	}

	for (int i = r - 1; i > a; i--) {
		if (board[i - 1][c - 1] == -1) board[i][c - 1] = 0;
		else
			board[i][c - 1] = board[i - 1][c - 1];
	}

	for (int i = c - 1; i >= 1; i--) {
		if (board[a][i - 1] == -1) board[a][i] = 0;
		else
			board[a][i] = board[a][i - 1];
	}

	
}

int compute() {
	int ans = 0;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (board[i][j] > 0)
				ans += board[i][j];
		}
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c >> t;

	vector<pair<int, int>> air_conditioner;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
			if (board[i][j] == -1)
				air_conditioner.push_back({ i, j });
		}
	}

	while (t--) {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (board[i][j] > 0)
					spread(i, j);
			}
		}

		add();

		up_conditioning(air_conditioner[0].X, air_conditioner[0].Y);
		down_conditioning(air_conditioner[1].X, air_conditioner[1].Y);
	}

	cout << compute();

}