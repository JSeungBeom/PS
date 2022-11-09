#include <bits/stdc++.h>

using namespace std;

int n;
int d[1005];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	d[1] = 1;
	d[2] = 2;

	if (n <= 2) {
		cout << d[n] % 10007;
		return 0;
	}

	for (int i = 3; i <= n; i++) {
		d[i] = (d[i - 1] + d[i - 2]) % 10007;
	}

	cout << d[n];
}