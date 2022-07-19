#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	deque<int> d;

	for (int i = 1; i <= n; i++) {
		d.push_back(i);
	}
	
	int cnt = 0;

	while (m--) {
		cin >> n;

		int idx;
		for (int i = 0; i < d.size(); i++) {
			if (d[i] == n) {
				idx = i;
			}
		}

		if (idx <= (d.size() / 2)) {
			while (d.front() != n) {
				d.push_back(d.front());
				d.pop_front();
				cnt++;
			}
		}
		else {
			while (d.front() != n) {
				d.push_front(d.back());
				d.pop_back();
				cnt++;
			}
		}

		d.pop_front();
	}

	cout << cnt;
}