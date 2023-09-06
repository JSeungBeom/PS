#include <bits/stdc++.h>

using namespace std;

int n;
int board[102][102];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int x, y;

	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		for (int j = x; j < x + 10; j++) {
			for (int k = y; k < y + 10; k++) {
				board[j][k] = 1;
			}
		}

	}

	int cnt = 0;

	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (board[i][j]) cnt++;
		}
	}

	cout << cnt;
}