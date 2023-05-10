#include <bits/stdc++.h>

using namespace std;

int v, e;
tuple<int, int, int> adj[100003];
vector<int> p(10005, 0);

int find(int x) {
	if (p[x] == x) return x;
	return p[x] = find(p[x]);
}

void unionParent(int u, int v) {
	u = find(u);
	v = find(v);

	if (u < v) p[u] = v;
	else p[v] = u;
}

bool is_diff_group(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v) return 0;
	return 1;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> v >> e;

	for (int i = 1; i <= v; i++) {
		p[i] = i;
	}

	int a, b, weight;
	for(int i = 0; i < e; i++) {
		cin >> a >> b >> weight;
		adj[i] = { weight, a, b };
	}

	sort(adj, adj + e);
	int cnt = 0;
	long long ans = 0;
		
	for (int i = 0; i < e; i++) {
		tie(weight, a, b) = adj[i];
		if (is_diff_group(a, b)) {
			unionParent(a, b);
			ans += weight;
			cnt++;
		}

		if (cnt == v - 1) break;
	}

	cout << ans;


}