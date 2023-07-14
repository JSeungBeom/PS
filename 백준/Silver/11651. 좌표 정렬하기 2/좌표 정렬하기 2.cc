#include <bits/stdc++.h>

using namespace std;

int n;

vector<pair<int, int>> xy;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else {
		return a.second < b.second;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int x, y;

	while (n--) {
		cin >> x >> y;
		xy.push_back({ x, y });
	}

	sort(xy.begin(), xy.end(), cmp);

	for (auto e : xy) {
		cout << e.first << ' ' << e.second << '\n';
	}
}