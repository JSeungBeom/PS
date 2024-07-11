#include <bits/stdc++.h>

using namespace std;

int n;
int A[105];
int B[105];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> B[i];
	}

	sort(A, A + n);
	sort(B, B + n);

	int ans = 0;

	for (int i = 0; i < n; i++) {
		ans += (A[i] * B[n - i - 1]);
	}

	cout << ans;
}