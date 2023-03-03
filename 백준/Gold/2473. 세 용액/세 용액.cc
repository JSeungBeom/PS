#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int n;
ll a[5003];
ll ans[3];
ll mn = 0x7f7f7f7f7f;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int idx = lower_bound(a, a + n, -a[i] -a[j]) - a;

			for (int k = -2; k <= 2; k++) {
				if (idx - k == i || idx - k == j) continue;
				if (idx - k >= n || idx - k < 0) continue;

				if (abs(a[i] + a[j] + a[idx - k]) < mn) {
					ans[0] = a[i];
					ans[1] = a[j];
					ans[2] = a[idx - k];
					mn = abs(a[i] + a[j] + a[idx -k]);
				}
			}
		}
	}

	sort(ans, ans + 3);

	cout << ans[0] << " " << ans[1] << " " << ans[2];

}