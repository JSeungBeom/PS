#include <bits/stdc++.h>

using namespace std;

int dist[20005];

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;

	fill(dist, dist + n + 1, -1);
	
	int mx = 0;

	dist[1] = 0;

	vector<int> adj[20005];

	for (int i = 0; i < edge.size(); i++) {
		adj[edge[i][0]].push_back(edge[i][1]);
		adj[edge[i][1]].push_back(edge[i][0]);
	}

	queue<int> q;
	q.push(1);

	while (!q.empty()) {
		int cur = q.front(); q.pop();

		for (int nxt : adj[cur]) {
			if (dist[nxt] >= 0) continue;
			dist[nxt] = dist[cur] + 1;
			mx = max(mx, dist[nxt]);
			q.push(nxt);
		}
	}

	for (int i = 1; i <= n; i++) {
		if(dist[i] == mx)
			answer++;
	}

	return answer;
}
