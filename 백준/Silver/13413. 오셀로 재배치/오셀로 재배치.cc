#include <bits/stdc++.h>

using namespace std;

int t, n;
char arr[100005];
char target[100005];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;

	while (t--) {
		cin >> n;

		for (int i = 0; i < n; i++)
			cin >> arr[i];

		for (int i = 0; i < n; i++)
			cin >> target[i];

		int wcnt = 0;
		int bcnt = 0;

		for (int i = 0; i < n; i++) {
			if (arr[i] == 'W' && target[i] == 'B')
				wcnt++;
			if (arr[i] == 'B' && target[i] == 'W')
				bcnt++;
		}

		int ans = wcnt > bcnt ? bcnt : wcnt;

		ans += abs(wcnt - bcnt);

		cout << ans << '\n';
	}
}