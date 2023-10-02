#include <bits/stdc++.h>

using namespace std;

int n;
int arr[2003];
long long dp[2003][2003];

long long solve(int l, int r, int cnt) {
	if (l > r) return 0;
	if (dp[l][r]) return dp[l][r];

	long long ans = max(solve(l + 1, r, cnt + 1) + arr[l] * cnt,
		solve(l, r - 1, cnt + 1) + arr[r] * cnt);

	return dp[l][r] = ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	cout << solve(1, n, 1);
}