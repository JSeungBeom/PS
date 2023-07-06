#include <bits/stdc++.h>

using namespace std;

int N;

vector<pair<int, int>> xy;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;

	int x, y;
	while (N--) {
		cin >> x >> y;
		xy.push_back({ x, y });
	}

	sort(xy.begin(), xy.end());

	for (auto e : xy)
		cout << e.first << ' ' << e.second << '\n';
}