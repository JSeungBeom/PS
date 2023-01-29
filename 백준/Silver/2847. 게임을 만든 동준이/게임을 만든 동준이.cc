#include <bits/stdc++.h>

using namespace std;

int n;
int a[103];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int ans = 0;

	for (int i = n - 1; i >= 0; i--) {
		while (a[i - 1] >= a[i]) {
			a[i - 1]--;
			ans++;
		}
	}

	cout << ans;
}
