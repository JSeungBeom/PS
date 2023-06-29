#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[502];
int p[502];
bool istree;
int t;

void DFS(int cur) {
	for (int nxt : adj[cur]) {
		if (p[cur] == nxt) continue;

		if (p[nxt] != 0) {
			istree = 0;
			continue;
		}

		p[nxt] = cur;
		DFS(nxt);
	}

}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		cin >> n >> m;

		if (n == 0 && m == 0) break;

		for (int i = 1; i <= n; i++) {
			adj[i].clear();
		}

		int ans = 0;

		fill(p, p + n + 2, 0);
		int u, v;

		while (m--) {
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		for (int i = 1; i <= n; i++) {
			istree = 1; 
			if (p[i] != 0) continue;
			DFS(i);
			ans += istree;
		}


		switch (ans) {
		case 0:
			cout << "Case " << ++t << ": No trees.\n";
			break;
		case 1:
			cout << "Case " << ++t << ": There is one tree.\n";
			break;

		default:
			cout << "Case " << ++t << ": A forest of " << ans << " trees.\n";
			break;
		}

	}
}