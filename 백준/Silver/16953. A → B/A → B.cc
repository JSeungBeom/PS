#include <bits/stdc++.h>
#define X first
#define Y second

using ll = long long;
using namespace std;

int a, b;
queue <pair<ll,ll>> q;
set<ll> vis;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b;

	q.push({ 1, a });

	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		if (cur.Y == b) {
			cout << cur.X; return 0;
		}

		for (ll nxt : {cur.Y * 2, cur.Y * 10 + 1}) {
			if (nxt > b) continue;
			if (vis.find(nxt) != vis.end()) continue;

			q.push({ cur.X + 1, nxt });
			vis.insert(nxt);
		}
	}

	cout << -1;


}