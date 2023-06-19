#include <bits/stdc++.h>
#define X first
#define Y second

#define INF 0x7f7f7f7f7f

using namespace std;
using ll = long long;

int n, m, k;

priority_queue <pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
vector<pair<int, int>> adj[100003];
ll d[100003];
vector<pair<ll, int>> ans;
void solve() {
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();

		if (d[cur.Y] != cur.X) continue;

		for (auto nxt : adj[cur.Y]) {
			if (d[nxt.Y] > d[cur.Y] + nxt.X) {
				d[nxt.Y] = d[cur.Y] + nxt.X;
				pq.push({ d[nxt.Y], nxt.Y });
			}
		}
	}

}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k;

	int u, v, c;

	while (m--) {
		cin >> u >> v >> c;
		adj[v].push_back({ c, u });
	}
	fill(d, d + n + 1, INF);
	int place;
	for (int i = 1; i <= k; i++) {
		cin >> place;
		d[place] = 0;
		pq.push({ d[place], place });
	}

	solve();
	int idx = max_element(d + 1, d + n + 1) - d;
	cout << idx << '\n' << d[idx];


}