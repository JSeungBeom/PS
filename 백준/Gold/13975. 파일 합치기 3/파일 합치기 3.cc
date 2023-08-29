#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int t, k;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--) {
		ll cost = 0;
		priority_queue<ll, vector<ll>, greater<ll>> pq;
		cin >> k;

		int num;
		while (k--) {
			cin >> num;
			pq.push(num);
		}

		while ((int)pq.size() > 1) {
			ll a = pq.top(); pq.pop();
			ll b = pq.top(); pq.pop();

			ll mixed = a + b;
			cost += mixed;
			pq.push(mixed);
		}

		cout << cost << '\n';
	}
	
}