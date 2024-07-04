#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[10];
int ans[10];
bool vis[10];

void back_tracking(int len) {
	if (len == m) {
		for (int i = 0; i < m; i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';

		return;
	}

	for (int i = 1; i <= n; i++) {
		if (vis[i])
			continue;

		vis[i] = 1;
		ans[len] = arr[i];
		back_tracking(len + 1);
		vis[i] = 0;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		arr[i] = i;

	back_tracking(0);

}