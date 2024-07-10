#include <bits/stdc++.h>

using namespace std;

int n;
int dp[1000006];
int pre[1000006];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	dp[1] = 0;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		pre[i] = i - 1;
		if (i % 3 == 0)
			if (dp[i] > dp[i / 3] + 1) {
				dp[i] = dp[i / 3] + 1;
				pre[i] = i / 3;
			}

		if (i % 2 == 0)
			if (dp[i] > dp[i / 2] + 1) {
				dp[i] = min(dp[i], dp[i / 2] + 1);
				pre[i] = i / 2;
			}
	}

	cout << dp[n] << '\n';

	int cur = n;

	while(cur){
		cout << cur << ' ';
		cur = pre[cur];
	}

}