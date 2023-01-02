#include <bits/stdc++.h>

using namespace std;

int n;
long long d[1000003];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	d[1] = 1;
	d[2] = 2;

	for (int i = 3; i <= n; i++) {
		d[i] = (d[i - 2] + d[i - 1]) % 15746;
	}

	cout << d[n];
}
