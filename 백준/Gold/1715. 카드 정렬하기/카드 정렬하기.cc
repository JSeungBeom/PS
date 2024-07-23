#include <bits/stdc++.h>

using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> pq;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int cards;

	while (n--) {
		cin >> cards;
		pq.push(cards);
	}

	int ans = 0;

	while (pq.size() > 1) {
		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();
		ans += a + b;
		pq.push(a + b);
	}

	cout << ans;
}