#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int n, m;
int u, v, b;
int k, s, e;

int d[252][252];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		fill(d[i], d[i] + n + 1, INF);
	}

	while (m--) {
		cin >> u >> v >> b;
		if (b == 1) {
			d[u][v] = 0;
			d[v][u] = 0;
		}
		else {
			d[u][v] = 0;
			d[v][u] = 1;
		}
	}

	for (int i = 1; i <= n; i++) {
		d[i][i] = 0;
	}

	for (int mid = 1; mid <= n; mid++) {
		for (int st = 1; st <= n; st++) {
			for (int en = 1; en <= n; en++) {
				if (d[st][en] > d[st][mid] + d[mid][en])
					d[st][en] = d[st][mid] + d[mid][en];
			}
		}
	}


	cin >> k;

	while (k--) {
		cin >> s >> e;
		cout << d[s][e] << '\n';
	}
}