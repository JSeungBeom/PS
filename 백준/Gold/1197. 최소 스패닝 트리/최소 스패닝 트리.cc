#include <bits/stdc++.h>

using namespace std;

int v, e;
int a, b, c;
vector<int> p(10005, -1);
tuple<int, int, int> edge[100005];

int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v) {
	u = find(u); v = find(v);

	if (u == v) return 0;
	if (p[u] == p[v]) p[u]--;
	if (p[u] < p[v]) p[v] = u;
	else p[u] = v;
	return 1;
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> v >> e;

	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		edge[i] = { c, a, b };
	}

	int cnt = 0;
	int cost = 0;

	sort(edge, edge + e);
	for (int i = 0; i < e; i++) {
		tie(c, a, b) = edge[i];

		if (!is_diff_group(a, b)) continue;

		cost += c;
		cnt++;

		if (cnt == v - 1) break;
	}

	cout << cost;
}