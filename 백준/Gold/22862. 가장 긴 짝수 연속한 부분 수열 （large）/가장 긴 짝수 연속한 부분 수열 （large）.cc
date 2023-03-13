#include <bits/stdc++.h>

using namespace std;

int n, k;
int a[1000003];
int cnt, ans;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];

	int en = 0;
	if (a[en] % 2 == 1) cnt++;

	for (int st = 0; st < n; st++) {
		while (en < n - 1 && cnt + a[en + 1] % 2 <= k) {
			en++;
			cnt += a[en] % 2;
		}

		ans = max(ans, en - st - cnt + 1);
		cnt -= a[st] % 2;
	}

	cout << ans;
}