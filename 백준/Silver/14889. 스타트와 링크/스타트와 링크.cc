#include <bits/stdc++.h>

using namespace std;

int n;
int board[22][22];
int team[22];

int mn = 0x7f7f7f7f;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	fill(team + n / 2, team + n, 1);

	do {
		int diff = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (team[i] != team[j]) continue;
				if (team[i] == 0) diff += board[i][j] + board[j][i];
				else diff -= board[i][j] + board[j][i];
			}
		}

		mn = min(abs(diff), mn);
	} while (next_permutation(team, team + n));

	cout << mn;
}