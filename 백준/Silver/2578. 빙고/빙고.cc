#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int board[5][5];
bool vis[5][5];

bool chk() {
	int bingo = 0;

	for (int i = 0; i < 5; i++) {
		int cnt = 0;
		for (int j = 0; j < 5; j++) {
			if (vis[i][j]) cnt++;
		}
		if (cnt == 5) bingo++;
	}

	for (int i = 0; i < 5; i++) {
		int cnt = 0;
		for (int j = 0; j < 5; j++) {
			if (vis[j][i]) cnt++;
		}
		if (cnt == 5) bingo++;
	}

	int cnt = 0;
	for (int i = 0; i < 5; i++) {
		if (vis[i][i]) cnt++;

		if (cnt == 5) bingo++;;
	}
	cnt = 0;

	for (int i = 0; i < 5; i++) {
		if (vis[i][4 - i]) cnt++;

		if (cnt == 5) bingo++;
	}

	return bingo >= 3;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> board[i][j];
		}
	}

	int num;
	int ans = 0;

	for (int i = 0; i < 25; i++) {
		cin >> num;

		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				if (board[j][k] == num)
					vis[j][k] = 1;
			}
		}

		ans++;

		if (chk()) {
			cout << ans;
			return 0;
		}
	}


}