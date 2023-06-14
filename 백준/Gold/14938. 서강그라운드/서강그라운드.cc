#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int n, m, r, t, a, b, l;
int items[103];
int d[103][103];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> r;
	
	for (int i = 1; i <= n; i++) {
		cin >> t;
		items[i] = t;
	}

	for (int i = 1; i <= n; i++) {
		fill(d[i], d[i] + n + 1, INF);
	}
	while (r--) {
		cin >> a >> b >> l;
		d[a][b] = l;
		d[b][a] = l;
	}

	for (int i = 1; i <= n; i++) {
		d[i][i] = 0;
	}

	for (int mid = 1; mid <= n; mid++) {
		for (int st = 1; st <= n; st++) {
			for (int en = 1; en <= n; en++) {
				d[st][en] = min(d[st][en], d[st][mid] + d[mid][en]);
			}
		}
	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		int mx = 0;
		for (int j = 1; j <= n; j++) {
			if (d[i][j] <= m) {
				mx += items[j];
			}
		}
		ans = max(ans, mx);
	}

	cout << ans;
}