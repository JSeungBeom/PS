#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n, m;
int u, v, cost;

vector<pair<int, int>> adj[1003];
vector<int> result;
int indegree[1003];
int dist[1003];
int s[1003];
queue<pair<int, int>> q;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	n++;

	while (m--) {
		cin >> u >> v >> cost;
		if (v == 1){ 
			adj[u].push_back({ cost, n });
			indegree[n]++;
		}
		else {
			adj[u].push_back({ cost, v });
			indegree[v]++;
		}
	}

	fill(dist, dist + n + 1, 0);

	q.push({0, 1});

	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		for (auto nxt : adj[cur.Y]) {
			if (dist[nxt.Y] < nxt.X + dist[cur.Y]) {
				dist[nxt.Y] = nxt.X + dist[cur.Y];
				s[nxt.Y] = cur.Y;
			}
			indegree[nxt.Y]--;
			if (indegree[nxt.Y] == 0) {
				q.push({ dist[nxt.Y], nxt.Y });
			}
		}
	}

	cout << dist[n] << '\n';

	int cur = n;
	while (cur) {
		result.push_back(cur);
		cur = s[cur];
	}

	reverse(result.begin(), result.end());

	for (int e : result) {
		if (e == n) cout << 1 << ' ';
		else cout << e << ' ';
	}
}