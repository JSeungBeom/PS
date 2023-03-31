#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[103];
int i, j, k;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	while (m--) {
		cin >> i >> j >> k;
		for (int c = i; c <= j; c++) {
			a[c] = k;
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << a[i] << " ";
	}

}