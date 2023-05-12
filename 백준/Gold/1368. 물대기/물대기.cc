#include <bits/stdc++.h>

using namespace std;

int n;
tuple<int, int, int> edges[100003];
int p[100003];
int e;

int find(int u) {
	if (p[u] == u) return u;
	else return p[u] = find(p[u]);
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

	int weight;

	cin >> n;

	for (int i = 0; i <= n; i++) {
		p[i] = i;
	}

	for (int i = 1; i <= n; i++) {
		cin >> weight;
		edges[e++] = { weight, 0, i };
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> weight;
			if (i >= j) continue;
			edges[e++] = { weight, i, j };
		}
	}
	n++;
	sort(edges, edges + e);

	int cnt = 0;
	int ans = 0;
	for (int i = 0; i < e; i++) {
		int weight, a, b;
		tie(weight, a, b) = edges[i];

		if (is_diff_group(a, b)) {
			ans += weight;
			cnt++;
		}

		if (cnt == n - 1) break;
	}

	cout << ans;


}