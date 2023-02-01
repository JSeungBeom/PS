#include <bits/stdc++.h>

using namespace std;

int n, m;
long long a[1003];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < m; i++) {
		sort(a, a + n);
		long long sum = a[0] + a[1];
		a[0] = a[1] = sum;
	}

	long long ans = 0;

	for (int i = 0; i < n; i++) {
		ans += a[i];
	}

	cout << ans;
}


// 4 6 6 3
// 3 4 6 6
// 7 7 6 6
// 12 12 7 7
// 14 14 12 12