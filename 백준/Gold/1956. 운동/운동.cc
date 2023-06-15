#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int v, e;
int d[402][402];
int a, b, c;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> v >> e;

	for (int i = 1; i <= v; i++) {
		fill(d[i], d[i] + v + 1, INF);
	}
	while (e--) {
		cin >> a >> b >> c;
		d[a][b] = c;
	}

	for (int i = 1; i <= v; i++) {
		d[i][i] = 0;
	}

	for (int mid = 1; mid <= v; mid++) {
		for (int st = 1; st <= v; st++) {
			for (int en = 1; en <= v; en++) {
				d[st][en] = min(d[st][en], d[st][mid] + d[mid][en]);
			}
		}
	}

	int ans = 0x7f7f7f7f;

	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (d[i][j] != 0 && d[i][j] != INF && d[j][i] != 0 && d[j][i] != INF)
				ans = min(ans, d[i][j] + d[j][i]);
		}
	}

	if (ans == 0x7f7f7f7f) cout << -1;
	else cout << ans;
}