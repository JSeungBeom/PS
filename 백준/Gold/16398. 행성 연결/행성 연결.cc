#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n;
priority_queue<
	tuple<int, int, int>, 
	vector<tuple<int, int, int>>, 
	greater<tuple<int, int, int>>> pq;

vector<pair<int, int>> adj[1000003];
bool vis[1000003];

int cost;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> cost;
			if (i >= j) continue;
			adj[i].push_back({ cost, j });
			adj[j].push_back({ cost, i });
		}
	}
	
	vis[1] = 1;
	
	for (auto nxt : adj[1])
		pq.push({ nxt.X, 1, nxt.Y });

	int cnt = 0;
	long long ans = 0;

	while (cnt < n - 1) {
		int weight, a, b;
		tie(weight, a, b) = pq.top(); pq.pop();
		if (vis[b]) continue;
		ans += weight;
		cnt++;
		vis[b] = 1;
		for (auto nxt : adj[b]) {
			if (!vis[nxt.Y])
				pq.push({ nxt.X, b, nxt.Y });
		}
	}

	cout << ans;

}