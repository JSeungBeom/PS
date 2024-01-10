#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, k;
ll dp[205][205];

int solve(int n, int k) {
	if (k == 1)
		return 1;

	if (dp[n][k])
		return dp[n][k];

	for (int i = 0; i <= n; i++) {
		dp[n][k] += (solve(n - i, k - 1) % 1000000000);
		dp[n][k] %= 1000000000;
	}

	return (dp[n][k] % 1000000000);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	cout << solve(n, k);
}

// 1 1 1 3 1 3 1 1 1 1 3 1 1 1 1 3
