#include <bits/stdc++.h>

using namespace std;

int n;
int p[1003];

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}

	sort(p, p + n);

	int ans = p[0];

	for (int i = 1; i < n; i++) {
		p[i] += p[i - 1];
		ans += p[i];
	}

	cout << ans;	
}