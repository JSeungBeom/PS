#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[100003];
int mn = 0x7fffffff;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);

	int st = 0, en = 0;

	while(en != n) {
		if (a[en] - a[st] >= m) {
			mn = min(mn, a[en] - a[st]);
			st++;
		}
		else
			en++;
	}

	cout << mn;
}