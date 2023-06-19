#include <bits/stdc++.h>

using namespace std;

int n;
int a[1002][12];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	fill(a[1], a[1] + 10, 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = j; k <= 9; k++) {
				a[i][j] = ((a[i][j] + a[i - 1][k]) % 10007);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i <= 9; i++) {
		ans += a[n][i];
	}


	cout << ans % 10007;
}

// 0 ~ 9
// 00 01 02 11 12 13 14 ~ 19