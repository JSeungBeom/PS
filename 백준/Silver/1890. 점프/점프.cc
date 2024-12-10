#include <iostream>
#include <cmath>

using namespace std;

int board[105][105];
long long dp[105][105];
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);


	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
		}
	}

	dp[1][1] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dp[i][j] == 0 || (i == n && j == n)) continue;

			if (board[i][j] + i <= n)
				dp[board[i][j] + i][j] = dp[board[i][j] + i][j] + dp[i][j];

			if (board[i][j] + j <= n)
				dp[i][board[i][j] + j] = dp[i][board[i][j] + j] + dp[i][j];
		}
	}

	cout << dp[n][n];
}