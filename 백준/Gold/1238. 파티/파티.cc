#include <bits/stdc++.h>
#define INF 0x7f7f7f7f
#define X first
#define Y second
using namespace std;

vector<pair<int, int>> adj[1003];
vector<pair<int, int>> rev_adj[1003];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> rev_pq;
int n, m, x;
int a, b, cost;

int dist[1003];
int rev_dist[1003];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> x;

	while (m--) {
		cin >> a >> b >> cost;
		adj[a].push_back({ cost, b });
		rev_adj[b].push_back({ cost, a });
	}

	fill(dist, dist + n + 1, INF);
	fill(rev_dist, rev_dist + n + 1, INF);
	
	dist[x] = 0;
	rev_dist[x] = 0;

	pq.push({ dist[x], x });
	rev_pq.push({ rev_dist[x],x });

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (dist[cur.Y] != cur.X) continue;

		for (auto nxt : adj[cur.Y]) {
			if (dist[nxt.Y] <= dist[cur.Y] + nxt.X) continue;
			dist[nxt.Y] = dist[cur.Y] + nxt.X;
			pq.push({ dist[nxt.Y], nxt.Y });
		}
	}

	while (!rev_pq.empty()) {
		auto cur = rev_pq.top(); rev_pq.pop();
		if (rev_dist[cur.Y] != cur.X) continue;

		for (auto nxt : rev_adj[cur.Y]) {
			if (rev_dist[nxt.Y] <= rev_dist[cur.Y] + nxt.X) continue;
			rev_dist[nxt.Y] = rev_dist[cur.Y] + nxt.X;
			rev_pq.push({ rev_dist[nxt.Y], nxt.Y });
		}
	}

	int mx = 0;
	for (int i = 1; i <= n; i++) {
		mx = max(mx, dist[i] + rev_dist[i]);
	}

	cout << mx;
}