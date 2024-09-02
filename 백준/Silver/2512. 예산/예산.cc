#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n, m;
int arr[10005];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int sum = 0;
	int mx = 0;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];

		sum += arr[i];
		mx = max(mx, arr[i]);
	}

	cin >> m;

	if (sum <= m) {
		cout << mx;
		return 0;
	}


	for (int i = m / n; i < m; i++) {
		sum = 0;

		for (int j = 0; j < n; j++) {
			if (arr[j] <= i)
				sum += arr[j];
			else
				sum += i;
		}
		if (sum > m) {
			cout << i - 1;
			return 0;
		}
	}


}