#include <bits/stdc++.h>

using namespace std;

int n, k;

int dist[200003];
int pre[200003];
queue<int> q;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	if (n == k) {
		cout << 0 << '\n';
		cout << n;
		return 0;
	}

	dist[n] = 0;
	q.push(n);

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int nx : {cur - 1, cur + 1, cur * 2}) {
			if (nx < 0 || nx > 200000) continue;
			if (dist[nx] != 0) continue;

			dist[nx] = dist[cur] + 1;
			pre[nx] = cur;
			q.push(nx);
		}
	}

	cout << dist[k] << '\n';

	int cur = k;
	vector<int> path;
	while (cur != n) {
		path.push_back(cur);
		cur = pre[cur];
	}

	path.push_back(cur);

	reverse(path.begin(), path.end());

	for (auto e : path) {
		cout << e << ' ';
	}
}