#include <bits/stdc++.h>

using namespace std;

int n, k;
int arr[100003];
int sum[100003];
int ans = -0x7f7f7f7f;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + arr[i];
	}

	for (int i = k; i <= n; i++) {
		ans = max(ans, sum[i] - sum[i - k]);
	}

	cout << ans << '\n';
}