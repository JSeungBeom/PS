#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[10];
int ans[10];
set<string> s;

void solve(int k, int st) {
	if (k == m) {
		for (int i = 0; i < k; i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
		return;
	};

	int tmp = -1;
	for (int i = st; i < n; i++) {
		if (arr[i] != tmp) {
			ans[k] = arr[i];
			tmp = ans[k];
			solve(k + 1, i);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	solve(0, 0);
}