#include <bits/stdc++.h>

using namespace std;

int n, r, q, u, v;
vector<int> adj[100003];
int p[100003];
int cnt[100003];

int DFS(int cur) {
	for (int nxt : adj[cur]) {
		if (p[cur] == nxt) continue;

		p[nxt] = cur;
		cnt[cur] += DFS(nxt);
	}

	cnt[cur]++;
	return cnt[cur];
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> r >> q;

	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	DFS(r);

	while (q--) {
		cin >> r;
		cout << cnt[r] << '\n';
	}
}