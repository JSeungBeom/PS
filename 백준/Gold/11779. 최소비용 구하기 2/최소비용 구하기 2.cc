#include <bits/stdc++.h>
#define X first
#define Y second
#define INF 0x7fffffff

using namespace std;

vector<pair<int, int>> adj[20005];
priority_queue<pair<int, int>, vector<pair<int, int>>,
greater<pair<int, int>>> pq;
int dist[20005];
int pre[20005];

int v, e, st, en;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> v >> e;

	int a, b, c;

	while (e--) {
		cin >> a >> b >> c;

		adj[a].push_back({ c, b });
	}

	cin >> st >> en;

	fill(dist, dist + v + 1, INF);

	dist[st] = 0;

	pq.push({ dist[st], st });

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();

		if (cur.X != dist[cur.Y]) continue;

		for (auto nxt : adj[cur.Y]) {
			if (dist[nxt.Y] > nxt.X + dist[cur.Y]) {
				dist[nxt.Y] = nxt.X + dist[cur.Y];
				pre[nxt.Y] = cur.Y;
				pq.push({ dist[nxt.Y], nxt.Y });
			}
		}
	}

	cout << dist[en] << '\n';

	vector<int> tmp;

	int cur = en;

	while (cur != st) {
		tmp.push_back(cur);
		cur = pre[cur];
	}
	tmp.push_back(cur);

	cout << tmp.size() << '\n';
	reverse(tmp.begin(), tmp.end());
	for (auto e : tmp)
		cout << e << ' ';
	
}