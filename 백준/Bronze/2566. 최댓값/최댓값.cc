#include <bits/stdc++.h>

using namespace std;

int board[9][9];
int mx;
pair<int, int> rc;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
			if (mx < board[i][j]) {
				mx = board[i][j];
				rc = { i, j };
			}
		}
	}

	cout << mx << '\n' << rc.first + 1 << ' ' << rc.second + 1;

}