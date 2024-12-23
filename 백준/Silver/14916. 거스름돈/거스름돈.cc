#include <iostream>
#include <cmath>

using namespace std;

int n;
int dp[100005];
const int MX = 0x7f7f7f7f;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	fill(dp, dp + 100005, MX);

	dp[2] = 1;
	dp[5] = 1;

	for (int i = 3; i <= n; i++) {
		if (dp[i - 2] > 0) {
			dp[i] = min(dp[i], dp[i - 2] + 1);
		}
		if (dp[i - 5] > 0) {
			dp[i] = min(dp[i], dp[i - 5] + 1);
		}
	}

	if (dp[n] == MX)
		cout << -1;
	else
		cout << dp[n];

}