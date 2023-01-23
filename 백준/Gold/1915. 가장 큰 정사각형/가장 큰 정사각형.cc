#include <bits/stdc++.h>

using namespace std;

int n, m;
string s;
int board[1003][1003];
int d[1003][1003];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> s;
		for (int j = 1; j <= m; j++) {
			board[i][j] = s[j - 1] - '0';
		}
	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (board[i][j])
				d[i][j] = min({ d[i - 1][j], d[i][j - 1], d[i - 1][j - 1] }) + 1;
			ans = max(ans, d[i][j]);
		}
	}

	cout << ans * ans;
}

/*
	1 1 1
	1 1 1    
	1 1 1

	1 1 1 1
	1 2 2 2
	1 2 3 3
	1 2 3 4
*/