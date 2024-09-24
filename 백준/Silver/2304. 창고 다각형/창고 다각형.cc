#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n, l, h;

int board[1005];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int mx = 0;

	while (n--) {
		cin >> l >> h;

		board[l] = h;

		mx = max(mx, h);
	}

	int cur = 0;
	int ans = 0;
	int l = 0, r = 0;

	for (int i = 1; i <= 1000; i++) {

		if (cur < board[i]) {
			ans += cur;
			cur = board[i];
		}
		else {
			ans += cur;
		}

		if (mx == board[i]) {
			l = i; break;
		}
	}

	cur = 0;

	for (int i = 1000; i >= 1; i--) {

		if (cur < board[i]) {
			ans += cur;
			cur = board[i];
		}
		else {
			ans += cur;
		}

		if (mx == board[i]) {
			r = i; break;
		}
	}

	ans += mx * (r - l + 1);

	cout << ans;
}