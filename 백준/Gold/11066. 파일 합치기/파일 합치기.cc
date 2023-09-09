#include <bits/stdc++.h>

using namespace std;

int t, k;
const int INF = 1e9;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--) {
		cin >> k;

		int num;
		int sum[503] = { 0 };
		int dp[503][503] = {0};

		for (int i = 1; i <= k; i++) {
			cin >> num;
			sum[i] = sum[i - 1] + num;
		}

		for (int i = 1; i <= k; i++) {
			for (int st = 1; st + i <= k; st++) {
				int en = st + i;

				int psum = sum[en] - sum[st - 1];
				dp[st][en] = INF;

				for (int mid = st; mid <= en; mid++) {
					dp[st][en] = min(dp[st][en],
						dp[st][mid] + dp[mid + 1][en] + psum);
				}
			}
		}
		cout << dp[1][k] << '\n';
	}
}