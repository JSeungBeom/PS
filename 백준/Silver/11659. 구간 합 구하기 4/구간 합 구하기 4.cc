#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[100005];
int psum[100005];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		psum[i] = psum[i - 1] + arr[i];
	}

	
	while (m--) {
		int i, j;

		cin >> i >> j;

		cout << psum[j] - psum[i - 1] << '\n';
	}
}