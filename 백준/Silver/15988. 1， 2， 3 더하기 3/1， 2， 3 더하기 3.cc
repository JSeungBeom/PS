#include <bits/stdc++.h>

using namespace std;

int t, n;
long long d[1000003];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	d[1] = 1;
	d[2] = 2;
	d[3] = 4;

	for (int i = 4; i <= 1000002; i++) {
		d[i] = (d[i - 3] + d[i - 2] + d[i - 1]) % 1000000009;
	}

	while (t--) {
		cin >> n;
		cout << d[n] << "\n";
	}
}
