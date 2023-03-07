#include <bits/stdc++.h>

using namespace std;

int n, s;
int a[100003];
int mn = 0x7fffffff;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int en = 0;
	int cnt = a[0];
	for (int st = 0; st < n; st++) {
		while (en < n && cnt < s) {
			en++;
			if(en != n)
			cnt += a[en];
		}
		if (en == n) break;

		mn = min(mn, en - st + 1);
		cnt -= a[st];
	}

	if (mn == 0x7fffffff) cout << 0;
	else
	cout << mn;
}