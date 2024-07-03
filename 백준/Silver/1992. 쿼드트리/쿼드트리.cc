#include <bits/stdc++.h>
using namespace std;

int N;
int board[100][100];

bool check(int x, int y, int n) {
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (board[x][y] != board[i][j]) {
				return false;
			}
		}
	}
	
	return true;
}

void func(int x, int y, int z) {
	if (check(x, y, z)) {
		cout << board[x][y];
		return;
	}

	cout << "(";
	int n = z / 2;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			func(x + n * i, y + n * j, n);
		}
	}
	cout << ")";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	string s;

	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < N; j++) {
			board[i][j] = s[j] - '0';
		}
	}

	func(0, 0, N);
}