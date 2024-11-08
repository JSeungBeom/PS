#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#define X first
#define Y second

using namespace std;

int n, m;
int board[1005][1005];
int dp[1005][1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = dp[i - 1][j];
			dp[i][j] = max(dp[i][j], dp[i][j - 1]);
			dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);

			dp[i][j] += board[i][j];

		}
	}

	cout << dp[n][m];
}

