#include <bits/stdc++.h>

using namespace std;

int n;
int a[100003];
int ans1 = 1e9 + 1;
int ans2 = 1e9 + 1;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		int idx = lower_bound(a, a + n, -a[i]) - a;

		if (idx < n && idx != i && abs(a[idx] + a[i]) < abs(ans1 + ans2)) {
			ans1 = a[i];
			ans2 = a[idx];
		}

		if (idx > 0 && idx - 1 != i && abs(a[idx - 1] + a[i]) < abs(ans1 + ans2)) {
			ans1 = a[i];
			ans2 = a[idx - 1];
		}

		if (idx + 1 < n && idx + 1 != i && abs(a[idx + 1] + a[i]) < abs(ans1 + ans2)) {
			ans1 = a[i];
			ans2 = a[idx + 1];
		}
	}

	if (ans1 > ans2) swap(ans1, ans2);

	cout << ans1 << " " << ans2;
}