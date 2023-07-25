#include <bits/stdc++.h>

using namespace std;

int n, k, w, v;
int W[103];
int V[103];
int dp[103][100003];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	
	for (int i = 1; i <= n; i++) {
		cin >> W[i] >> V[i];
	}

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= k; j++) {
			if (j - W[i] >= 0)dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i]);
			else dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[n][k];
}