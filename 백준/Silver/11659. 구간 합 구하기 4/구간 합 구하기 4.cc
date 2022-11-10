#include <bits/stdc++.h>

using namespace std;

int n, m, i, j;

int d[100002];
int arr[100002];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	d[1] = arr[1];

	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 1] + arr[i];
	}

	while (m--) {
		cin >> i >> j;
		cout << d[j] - d[i - 1] << "\n";
	}
}