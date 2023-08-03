#include <bits/stdc++.h>

using namespace std;

int n;
int arr[1003];
int max_dp[1003];
int min_dp[1003];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (arr[j] < arr[i]) {
				max_dp[i] = max(max_dp[j] + 1, max_dp[i]);
			}
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j >= i; j--) {
			if (arr[j] < arr[i]) {
				min_dp[i] = max(min_dp[j] + 1, min_dp[i]);
			}
		}
	}

	int mx = 0;

	for (int i = 0; i < n; i++) {
		 mx = max(mx, max_dp[i] + min_dp[i]);
	}

	cout << mx + 1;
}