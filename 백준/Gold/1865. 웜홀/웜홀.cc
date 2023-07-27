#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
using namespace std;

int tc, n, m, w;
int s, e, t;

vector<tuple<int, int, int>> adj;
int dist[502];

bool bellmanFord() {
	dist[1] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < adj.size(); j++) {
			int to, from, cost;
			tie(from ,to, cost) = adj[j];

			if (dist[to] > dist[from] + cost)
				dist[to] = dist[from] + cost;
		}
	}

	for (int j = 0; j < adj.size(); j++) {
		int to, from, cost;
		tie(from, to, cost) = adj[j];
		
		if (dist[to] > dist[from] + cost) return 1;
	}

	return 0;


	return 0;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;

	while (tc--) {
		cin >> n >> m >> w;

		fill(dist, dist + n + 1, 0);
		adj.clear();

		for(int i = 0; i < m; i++) {
			cin >> s >> e >> t;
			adj.push_back({ e, s, t });
			adj.push_back({ s, e, t });
		}

		for(int j = 0; j < w; j++) {
			cin >> s >> e >> t;
			adj.push_back({ s, e, -t });
		}

		if (bellmanFord()) cout << "YES\n";
		else cout << "NO\n";
	}
}