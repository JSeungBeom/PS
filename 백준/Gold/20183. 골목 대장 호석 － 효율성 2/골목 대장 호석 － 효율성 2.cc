#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define X first
#define Y second


using ll = long long;
using namespace std;

int n, m, a, b, c;
int u, v, cost;

vector<pair<ll, int>> adj[100003];
int dist[100003];
bool solve(int weight) {
	fill(dist, dist + n + 1, INF);
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	dist[a] = 0;
	pq.push({ dist[a], a });

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();

		if (dist[cur.Y] != cur.X) continue;

		for (auto nxt : adj[cur.Y]) {
			if (nxt.X > weight) continue;
			if (dist[nxt.Y] > dist[cur.Y] + nxt.X) {
				dist[nxt.Y] = dist[cur.Y] + nxt.X;
				pq.push({ dist[nxt.Y], nxt.Y });
			}
		}
	}


	return dist[b] <= c;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> a >> b >> c;

	int mx = 0;

	while (m--) {
		cin >> u >> v >> cost;
		adj[u].push_back({ cost, v });
		adj[v].push_back({ cost, u });
		mx = max(cost, mx);
	}

	int st = 1;
	int en = mx;

	while (st < en) {
		int mid = (st + en) / 2;
		if (solve(mid)) en = mid;
		else st = mid + 1;
	}

	if (solve(st)) cout << st;
	else cout << -1;

}