#include <bits/stdc++.h>

using namespace std;

int n, q;
set<int> place;

int main(void) {
	ios::sync_with_stdio(0);	cin.tie(0);

	cin >> n >> q;

	int num;
	int cur = 1;

	for (int i = 1; i <= n; i++) {
		cin >> num;
		if (num) place.insert(i);
	}

	int query, x;
	for (int i = 0; i < q; i++) {
		cin >> query;
		if (query == 1) {
			cin >> x;
			if (place.find(x) != place.end())
				place.erase(x);
			else
				place.insert(x);
		}
		else if (query == 2) {
			cin >> x;
			cur = (cur + x - 1) % n + 1;
		}
		else {
			if (place.empty()) {
				cout << -1 << "\n";
				continue;
			}
			auto it = place.lower_bound(cur);
			if (it != place.end()) {
				cout << *it - cur << "\n";
			}
			else
				cout << n - cur + *place.begin() << "\n";
		}
	}
}