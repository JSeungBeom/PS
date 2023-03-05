#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int n, c;
int a[200003];

bool solve(int len) {
	int idx = 0, cnt = 0;
	while (idx != n) {
		idx = lower_bound(a + idx, a + n, a[idx] + len) - a;
		cnt++;
	}

	return cnt >= c;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	sort(a, a + n);

	int st = 0;
	int en = 1e9;

	while (st < en) {
		int mid = (st + en + 1) / 2;
		if (solve(mid)) st = mid;
		else en = mid - 1;
	}

	cout << st;
}

// 1 2 4 8 9