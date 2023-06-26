#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n, m;
vector<int> adj[32003];
int indegree[32003];
priority_queue<int, vector<int>, greater<int>> q;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int u, v;
	while (m--) {
		cin >> u >> v;
		adj[u].push_back(v);
		indegree[v]++;
	}

	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		auto cur = q.top(); q.pop();
		cout << cur << ' ';
		for (auto nxt : adj[cur]) {
			indegree[nxt]--;
			if (indegree[nxt] == 0)
				q.push(nxt);
		}
	}




}