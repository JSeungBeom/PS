#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int v, e;
int cost;
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
	greater<tuple<int, int, int>>> pq;
vector<pair<int, int>> adj[1005];
bool vis[1005];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> v;


	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			cin >> cost;

			if (i >= j) continue;

			adj[i].push_back({ cost, j });
			adj[j].push_back({ cost, i });
		}
	}

	vis[1] = 1;

	for (auto nxt : adj[1]) {
		pq.push({ nxt.X, 1, nxt.Y });
	}

	int cnt = 0;
	long long ans = 0;

	while (cnt < v - 1) {
		int a, b, c;
		tie(c, a, b) = pq.top(); pq.pop();
		if (vis[b]) continue;
		vis[b] = 1;
		ans += c;
		cnt++;

		for (auto nxt : adj[b]) {
			if (vis[nxt.Y]) continue;

			pq.push({ nxt.X, b, nxt.Y });
		}
	}

	cout << ans;

}