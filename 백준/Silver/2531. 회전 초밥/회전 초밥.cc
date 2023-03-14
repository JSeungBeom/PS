#include <bits/stdc++.h>

using namespace std;

int n, d, k, c;
int a[30003 * 2];
int chk[3003];
int mx;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> d >> k >> c;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i + n] = a[i];
	}

	chk[c]++;
	int ans = 1;

	for (int i = 0; i < n * 2; i++) {
		if (i >= k) {
			chk[a[i - k]]--;
			if (chk[a[i - k]] == 0) ans--;
		}
			if (chk[a[i]] == 0) {
				ans++;
				mx = max(mx, ans);
			}
			chk[a[i]]++;
	}

	cout << mx;
}