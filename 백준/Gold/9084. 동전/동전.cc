#include <bits/stdc++.h>

using namespace std;

int t, n, m;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--) {
		int a[23] = { 0 };
		int d[10003] = { 0 };
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		cin >> m;

		d[0] = 1;

		for (int i = 0; i < n; i++) {
			for (int j = a[i]; j <= m; j++) {
				d[j] += d[j - a[i]];
			}
		}

		cout << d[m] << "\n";
	}

}