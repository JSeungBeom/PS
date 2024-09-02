#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n, x;
int arr[250005];
int sum[250005];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> x;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	
	sum[1] = arr[1];

	for (int i = 2; i <= n; i++) {
		sum[i] = sum[i - 1] + arr[i];
	}

	int mx = 0;

	for (int i = x; i <= n; i++) {
		mx = max(mx, sum[i] - sum[i - x]);
	}

	if (mx == 0) {
		cout << "SAD";
		return 0;
	}

	int cnt = 0;

	for (int i = x; i <= n; i++) {
		if (sum[i] - sum[i - x] == mx) cnt++;
	}

	cout << mx << '\n' << cnt;
}