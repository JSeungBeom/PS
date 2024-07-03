#include <bits/stdc++.h>

using namespace std;

int board[3005][3005];
int n;
int cnt[3];

bool chk(int n, int r, int c) {
	for (int i = r; i < r + n; i++) {
		for (int j = c; j < c + n; j++) {
			if (board[r][c] != board[i][j])
				return 0;
		}
	}
	
	return 1;
}
void func(int n, int r, int c) {
	if (chk(n, r, c)) {
		cnt[board[r][c] + 1]++;
		return;
	}

	int x = n / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			func(x, x * i + r, x * j + c);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	
	func(n, 0, 0);

	for (int i = 0; i < 3; i++) {
		cout << cnt[i] << '\n';
	}
}