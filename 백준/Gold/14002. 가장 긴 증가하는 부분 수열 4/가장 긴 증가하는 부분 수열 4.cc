#include <bits/stdc++.h>
using namespace std;

int n;
int a[1003];
int dp[1003];
int s[1003];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (a[i] > a[j]) {
				if (dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
					s[i] = j;
				}
			}
		}
	}

	int maxi = 1, maxd = dp[1];
	for (int i = 2; i <= n; i++) {
		if (maxd < dp[i]) {
			maxd = dp[i];
			maxi = i;
		}
	}

	deque<int> ans;
	int cur = maxi;
	while (cur) {
		ans.push_front(a[cur]);
		cur = s[cur];
	}

	cout << ans.size() << '\n';
	for (auto e : ans) cout << e << ' ';
}