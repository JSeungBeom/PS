#include <bits/stdc++.h>

using namespace std;

int n, m, cnt;
int a[10003];

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int en = 1;
	int sum = a[0];
	
	for (int st = 0; st < n; st++) {
		while (en < n && sum < m) {
			sum += a[en];
			en++;
		}

		if (sum == m) {
			cnt++;
		}

		sum -= a[st];
	}

	cout << cnt;
}