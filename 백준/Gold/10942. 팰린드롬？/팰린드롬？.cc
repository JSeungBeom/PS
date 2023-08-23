#include <bits/stdc++.h>

using namespace std;

int n, m, s, e;
int arr[2003];
bool dp[2003][2003];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		dp[i][i] = 1;
	}

	for (int i = 1; i < n; i++) {
		if (arr[i] == arr[i + 1])
			dp[i][i + 1] = 1;
	}

	for (int i = n - 1; i >= 1; i--) {
		for (int j = i + 1; j <= n; j++) {
			if (dp[i + 1][j - 1] == 1 && arr[i] == arr[j])
				dp[i][j] = 1;
		}
	}

	cin >> m;

	while (m--) {
		cin >> s >> e;
		cout << dp[s][e] << '\n';
	}
}