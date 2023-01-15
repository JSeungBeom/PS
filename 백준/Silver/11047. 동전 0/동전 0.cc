#include <bits/stdc++.h>

using namespace std;

int n, k;
int arr[12];
int ans;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = n; i >= 1; i--) {
		ans += k / arr[i];
		k %= arr[i];
	}

	cout << ans;
}

