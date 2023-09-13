#include <bits/stdc++.h>

using namespace std;

int n;
int a[1005];
int dp[1005];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (a[i] < a[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	cout << *max_element(dp, dp + n + 1) + 1;
}

