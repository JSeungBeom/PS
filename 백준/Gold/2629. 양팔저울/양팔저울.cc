#include <bits/stdc++.h>

using namespace std;

int n, k;
int P[32];
int B[32];
bool dp[32][40002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	dp[0][0] = 1;

	for (int i = 1; i <= n; i++) {
		cin >> P[i];
		dp[i][0] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 40000; j++) {
			dp[i][j] = dp[i - 1][j] || dp[i - 1][abs(j - P[i])];
			if(j + P[i] <= 40000) dp[i][j] = dp[i][j] || dp[i - 1][j + P[i]];
		}
	}

	cin >> k;

	int q;

	while (k--) {
		cin >> q;
		if (dp[n][q]) cout << "Y ";
		else cout << "N ";
	}


}