#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[200003];
int chk[100003];
int ans;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int en = 0;
	chk[a[en]]++;

	for (int st = 0; st < n; st++) {
		while (en + 1 != n && chk[a[en + 1]] < k) {
			en++;
			chk[a[en]]++;
		}

		ans = max(ans, en - st + 1);
		chk[a[st]]--;
	}

	cout << ans;
}
