#include <bits/stdc++.h>

using namespace std;

int n, r, c;
int row[502];
int col[502];

int dp[502][502];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> row[i] >> col[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int st = 1; st + i <= n; st++) {
			int en = st + i;

			dp[st][en] = 0x7f7f7f7f;

			for (int mid = st; mid <= en; mid++) {
				dp[st][en] = min(dp[st][en],
					dp[st][mid] + dp[mid + 1][en] + row[st] * col[mid] * col[en]);
			}
		}
	}

	cout << dp[1][n] << '\n';
}