#include <bits/stdc++.h>
using namespace std;

int N;
char board[10000][10000];

void fill_star(int x, int y) {
	board[x][y] = '*';
	board[x + 1][y - 1] = '*';
	board[x + 1][y + 1] = '*';
	for (int i = y - 2; i <= y + 2; i++) {
		board[x + 2][i] = '*';
	}
}
void func(int n, int x, int y) {
	if (n == 3) {
		fill_star(x, y);
		return;
	}

	int z = n / 2;

	func(z, x, y);
	func(z, x + z, y - z);
	func(z, x + z, y + z);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;


	int z = N / 3 * 2;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N * 2 - 1; j++) {
			board[i][j] = ' ';
		}
	}

	func(N, 0, N - 1);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N * 2 - 1; j++) {
				cout << board[i][j];
		}
		cout << "\n";
	}
}