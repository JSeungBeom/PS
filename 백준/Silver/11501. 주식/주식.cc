#include <bits/stdc++.h>

using namespace std;
int a[1000003];

int t, n;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--) {
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		int mx = a[n - 1];
		long long ans = 0;

		for (int i = n - 2; i >= 0; i--) {
			if (a[i] > mx) mx = a[i];
			ans += mx - a[i];
		}

		cout << ans << "\n";
	}
}