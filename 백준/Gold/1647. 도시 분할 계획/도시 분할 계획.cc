#include <bits/stdc++.h>

using namespace std;

int n, m;
int cost, a, b;
tuple<int, int, int> edges[1000003];
int p[100003];

int find(int u) {
	if (p[u] == u) return u;
	return p[u] = find(p[u]);
}

bool is_diff_group(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v) return 0;
	if (p[u] > p[v]) p[u] = v;
	else p[v] = u;

	return 1;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		p[i] = i;
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> cost;	
		edges[i] = { cost , a, b };
	}

	sort(edges, edges + m);
	
	int ans = 0;
	int cnt = 0;
	int mx = 0;

	for (int i = 0; i < m; i++) {
		int a, b, cost;
		tie(cost, a, b) = edges[i];

		if (is_diff_group(a, b)) {
			cnt++;
			ans += cost;
			mx = max(mx, cost);
		}

		if (cnt == n - 1)
			break;
	}

	cout << ans - mx;
}