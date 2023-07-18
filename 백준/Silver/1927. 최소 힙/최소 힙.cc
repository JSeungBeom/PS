#include <bits/stdc++.h>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
int x;
int n;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	while (n--) {
		cin >> x;
		if (x != 0) {
			pq.push(x);
		}
		else {
			if (pq.empty()) {
				cout << 0 << '\n';
			}
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
	}

}