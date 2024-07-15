#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m;
int a[1000005];

bool chk(int target) {
	ll cur = 0;

	for (int i = 0; i < n; i++) cur += a[i] / target;

	return cur >= m;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	ll st = 0;
	ll en = 1e9;

	while (st < en) {
		ll mid = (st + en + 1) / 2;
		if (chk(mid)) st = mid;
		else en = mid - 1;
	}

	cout << st;
}