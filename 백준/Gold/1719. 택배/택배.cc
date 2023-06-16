#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int n, m;
int d[203][203];
int s[203][203];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int u, v, cost;
	for (int i = 1; i <= n; i++) {
		fill(d[i], d[i] + n + 1, INF);
	}

	while (m--) {
		cin >> u >> v >> cost;
		d[u][v] = cost;
		d[v][u] = cost;
		s[u][v] = v;
		s[v][u] = u;
	}

	for (int i = 1; i <= n; i++) {
		d[i][i] = 0; s[i][i] = 0;
	}

	for (int mid = 1; mid <= n; mid++) {
		for (int st = 1; st <= n; st++) {
			for (int en = 1; en <= n; en++) {
				if (d[st][en] > d[st][mid] + d[mid][en]) {
					d[st][en] = d[st][mid] + d[mid][en];
					s[st][en] = s[st][mid];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (s[i][j] == 0) cout << "- " ;
			else cout << s[i][j] << ' ';
		}
		cout << '\n';
	}
}