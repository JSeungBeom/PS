#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

deque<pair<int, int>> dq;
int n, k;

void rotate() {

	auto tmp = dq.back();
	dq.pop_back();
	dq.push_front(tmp);


	if (dq[n - 1].Y)
		dq[n - 1].Y = 0;
}

void move() {
	for (int i = n - 2; i >= 0; i--) {
		if (dq[i].Y == 1 && dq[i + 1].X > 0 && dq[i + 1].Y == 0) {
			dq[i].Y = 0;
			dq[i + 1].Y = 1;
			dq[i + 1].X--;
		}
	}

	if(dq[n - 1].Y)
		dq[n - 1].Y = 0;
}

void lift() {
	if (dq[0].X != 0) {
		dq[0].Y = 1;
		dq[0].X--;
	}
}

bool chk() {
	int cnt = 0;

	for (auto e : dq) {
		if (e.X == 0)
			cnt++;
	}

	if (cnt >= k) return 0;

	return 1;
}

int main(void) {
	ios::sync_with_stdio(0);

	cin >> n >> k;

	int durab;

	for (int i = 1; i <= 2 * n; i++) {
		cin >> durab;
		dq.push_back({ durab, 0 });
	}

	int s = 0;

	while (chk()) {
		s++;
		rotate();
		move();
		lift();
	}

	cout << s;
}