#include <bits/stdc++.h>

using namespace std;

int t, n, m;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	int num;
	 
	while (t--) {
		cin >> n >> m;
		queue<pair<int, int>> q;
		priority_queue<int> pq;
		for (int i = 0; i < n; i++) {
			cin >> num;
			q.push({ num, i });
			pq.push(num);
		}

		int cnt = 0;

		while (!q.empty()) {
			auto cur = q.front(); q.pop();
			int mx = pq.top();

			if (cur.first < mx) {
				q.push(cur);
			}
			else {
				pq.pop(); cnt++;
				if (cur.second == m) {
					cout << cnt << '\n'; break;
				}
			}
		}
	}


}