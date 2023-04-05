#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int num;
int n;
priority_queue<ll, vector<ll>, greater<ll>> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num;
		pq.push(num);
	}

	long long ans = 0;
	while (pq.size() > 1) {
		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();

		ans += a + b;
		pq.push(a + b);
	}
	
	cout << ans;
}