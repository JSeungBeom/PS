#include <bits/stdc++.h>

using namespace std;

int T, n;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;

	while (T--) {
		cin >> n;
		int arr[100003][3], d[100003][3];

		for (int i = 1; i <= n; i++) {
			cin >> arr[i][1];
		}
		for (int i = 1; i <= n; i++) {
			cin >> arr[i][2];
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 2; j++) {
				int tmp = 0;
				if (i > 2) tmp = max(d[i - 2][1], d[i - 2][2]);
				if (i > 1) tmp = max(tmp, d[i - 1][3 - j]);
				d[i][j] = tmp + arr[i][j];
			}
		}
		cout << max(d[n][1], d[n][2]) << "\n";
	}
	
}