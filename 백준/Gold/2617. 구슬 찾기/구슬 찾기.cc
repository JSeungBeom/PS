#include <bits/stdc++.h>

using namespace std;

int n, m;
int u, v;
vector<int> adj_h[103];
vector<int> adj_l[103];
bool vis[103];


int heavier[103];
int lighter[103];
int ans;
bool DFS(vector<int> v[], int st) {
	fill(vis, vis + n + 1, 0);
	stack<int> s;
	vis[st] = 1;
	s.push(st);

	int cnt = 0;
	
	while (!s.empty()) {
		auto cur = s.top(); s.pop();
		for(auto nxt : v[cur]) {
			if (vis[nxt]) continue;
			vis[nxt] = 1;
			cnt++;
			s.push(nxt);
		}
	}

	return cnt >= (n + 1) / 2;
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	while (m--) {
		cin >> u >> v;
		adj_h[u].push_back(v);
		adj_l[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		ans += (DFS(adj_h, i) || DFS(adj_l, i));
	}

	cout << ans;
}