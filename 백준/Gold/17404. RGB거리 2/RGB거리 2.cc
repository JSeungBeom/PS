#include <bits/stdc++.h>
#define MAX 0x7f7f7f7f
using namespace std;

int n;
int board[1005][4];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> board[i][j];
		}
	}

	int ans = MAX;

	for (int st = 1; st <= 3; st++) {
		int dp[1005][4] = { 0 };

		for (int j = 1; j <= 3; j++) {
			if (j == st) dp[1][st] = board[1][st];
			else dp[1][j] = MAX;
		}

		for (int j = 2; j <= n; j++) {
			dp[j][1] = min(dp[j - 1][2], dp[j - 1][3]) + board[j][1];
			dp[j][2] = min(dp[j - 1][1], dp[j - 1][3]) + board[j][2];
			dp[j][3] = min(dp[j - 1][1], dp[j - 1][2]) + board[j][3];
		}

		for (int j = 1; j <= 3; j++) {
			if (j == st) continue;
			ans = min(dp[n][j], ans);
		}
	}

	cout << ans;


}