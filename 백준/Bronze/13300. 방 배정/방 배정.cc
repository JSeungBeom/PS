#include <bits/stdc++.h>	

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k, s, y;

	cin >> n >> k;

	int m[7] = {};
	int w[7] = {};

	while (n--) {
		cin >> s >> y;
		if (s == 0) {
			w[y]++;
		}
		else if (s == 1) {
			m[y]++;
		}
	}

	int cnt = 0;

	for (int i = 1; i < 7; i++) {
		if (w[i] == 0) {
			continue;
		}
		else if (w[i] <= k) {
			cnt++;
		}
		else {
			cnt++;
			while (w[i] > k) {
				cnt++;
				w[i] -= k;
			}
		}
	}

	for (int i = 1; i < 7; i++) {
		if (m[i] == 0) {
			continue;
		}
		else if (m[i] <= k) {
			cnt++;
		}
		else {
			cnt++;
			while (m[i] > k) {
				cnt++;
				m[i] -= k;
			}
		}
	}

	cout << cnt;
}