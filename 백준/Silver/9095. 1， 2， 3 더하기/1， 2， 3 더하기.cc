#include <bits/stdc++.h>

using namespace std;

int T, n;
int d[15];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;

	d[1] = 1;
	d[2] = 2;
	d[3] = 4;

	while (T--) {
		cin >> n;
		for (int i = 4; i <= n; i++) {
			d[i] = d[i - 1] + d[i - 2] + d[i - 3];
		}

		cout << d[n] << "\n";
	}
}