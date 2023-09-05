#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n, m;
int u, v, cost;
int cnt;

vector<int> p(1005, -1);
tuple<int, int, int> edges[1000005];

int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v) return 0;
	if (p[u] == p[v]) p[u]--;
	if (p[u] < p[v]) p[v] = u;
	else p[u] = v;
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i <= m; i++) {
		cin >> u >> v >> cost;
		if (cost == 1)
			edges[i] = { 0, u, v };
		else
			edges[i] = { 1, u, v };
	}

	sort(edges, edges + m + 1);
	int mx = 0, mn = 0;

	for (int i = 0; i <= m; i++) {
		int a, b, co;
		tie(co, a, b) = edges[i];


		if (!is_diff_group(a, b)) continue;
		
		mn += co;
		cnt++;
		if (cnt == n) break;
	}

	fill(p.begin(), p.end(), -1);
	reverse(edges, edges + m + 1);
	cnt = 0;

	for (int i = 0; i <= m; i++) {
		int a, b, co;
		tie(co, a, b) = edges[i];

		if (!is_diff_group(a, b)) continue;

		mx += co;
		cnt++;
		if (cnt == n) break;
	}

	cout << mx * mx - mn * mn;
}