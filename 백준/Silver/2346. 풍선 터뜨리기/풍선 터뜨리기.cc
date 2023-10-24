#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n;
deque<pair<int, int>> balloons;
stack<int> ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int num;
	for (int i = 1; i <= n; i++) {
		cin >> num;
		balloons.push_back({i, num});
	}

	while (!balloons.empty()) {
		auto cur = balloons.front(); balloons.pop_front();
		cout << cur.X << ' ';
		int nxt = cur.Y;

		if (nxt >= 0) {
			nxt--;

			while (!balloons.empty() && nxt-- ) {
				balloons.push_back(balloons.front());
				balloons.pop_front();

			}
		}
		else {
			while (!balloons.empty() && nxt++) {
				balloons.push_front(balloons.back());
				balloons.pop_back();
			}
		}
	}

	
}