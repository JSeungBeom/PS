#include <bits/stdc++.h>

using namespace std;

int n;
int stairs[305];
int dp[305][3];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> stairs[i];
	}

	dp[1][1] = stairs[1];

	for (int i = 2; i <= n; i++) {
		dp[i][1] = max(dp[i - 2][1], dp[i - 2][2]) + stairs[i];
		dp[i][2] = dp[i - 1][1] + stairs[i];
	}

	cout << max(dp[n][1], dp[n][2]);
}