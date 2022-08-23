#include <bits/stdc++.h>

using namespace std;

int k, num, dir;
int board[10][10];
bool connected[3];
bool vis[4];

void reset_vis() {
	for (int i = 0; i < 4; i++) {
		vis[i] = 0;
	}
}

void rotate(int num, int dir) {
	vis[num] = 1;
	if (dir == 1) {
		int tmp = board[num][7];
		for (int i = 6; i >= 0; i--) {
			board[num][i + 1] = board[num][i];
		}
		board[num][0] = tmp;
	}
	else {
		int tmp = board[num][0];
		for (int i = 1; i < 8; i++) {
			board[num][i - 1] = board[num][i];
		}
		board[num][7] = tmp;
	}

	if (num != 0 && !vis[num - 1] && connected[num - 1]) {
		rotate(num - 1, -dir);
	}

	if (num != 3 && !vis[num + 1] && connected[num]) {
		rotate(num + 1, -dir);
	}
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;

	for (int i = 0; i < 4; i++) {
		cin >> s;
		for (int j = 0; j < 8; j++) {
			board[i][j] = s[j] - '0';
		}
	}

	for (int i = 0; i < 3; i++) {
		if (board[i][2] != board[i + 1][6])
			connected[i] = 1;
	}

	cin >> k;
	while (k--) {
		cin >> num >> dir;
		int brute = num - 1;
		for (int i = 0; i < 3; i++) {
			if (board[i][2] != board[i + 1][6])
				connected[i] = 1;
		}
		rotate(brute, dir);
		reset_vis();
		for (int i = 0; i < 3; i++) {
			connected[i] = 0;
		}
	}



	int score = 0;
	int doubles = 1;
	for (int i = 0; i < 4; i++) {
	
		if (board[i][0] == 1) {
			score += doubles;
		}
		doubles *= 2;
	}

	cout << score;

}