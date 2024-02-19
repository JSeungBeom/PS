#include <bits/stdc++.h>

using namespace std;

int t, n, k, x, y, w;
vector<int> adj[100005];
int indeg[100005];
int tim[100005];
int ans[100005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--) {
		cin >> n >> k;

		fill(indeg, indeg + 100005, 0);
		fill(tim, tim + 100005, 0);
		fill(ans, ans + 100005, 0);

		queue<int> q;

		for (int i = 1; i <= n; i++) {
			adj[i].clear();
		}

		for (int i = 1; i <= n; i++) {
			cin >> tim[i];
		}

		for (int i = 1; i <= k; i++) {
			cin >> x >> y;
			adj[x].push_back(y);
			indeg[y]++;
		}

		cin >> w;

		for (int i = 1; i <= n; i++) {
			if (indeg[i] == 0)
				q.push(i);

			ans[i] = tim[i];
		}

		while (!q.empty()) {
			int cur = q.front(); q.pop();

			for (int nxt : adj[cur]) {
				indeg[nxt]--;

				ans[nxt] = max(ans[nxt], ans[cur] + tim[nxt]);

				if (indeg[nxt] == 0)
					q.push(nxt);
			}
		}

		cout << ans[w] << '\n';
	}


}