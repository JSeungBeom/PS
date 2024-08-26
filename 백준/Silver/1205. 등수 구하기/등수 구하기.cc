#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n, score, p;
long long arr[52];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> score >> p;

	if (n == 0) {
		cout << 1;
		return 0;
	}

	fill(arr, arr + 52, -1);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	int cnt = 1;

	for (int i = 0; i < p; i++) {
		if (score == arr[i]) {
			continue;
		}

		if (score > arr[i]) {
			cout << cnt;
			return 0;
		}

		cnt++;
	}

	cout << -1;
}