#include <bits/stdc++.h>

using namespace std;

int x, n, a, b;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> x >> n;

	int ans = 0;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		ans += a * b;
	}

	if (x == ans) cout << "Yes";
	else cout << "No";
}