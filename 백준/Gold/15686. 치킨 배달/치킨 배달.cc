#include <bits/stdc++.h>
using namespace std;

int n, m;
int city[52][52];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	vector<pair<int, int>> home;
	vector<pair<int, int>> chicken;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> city[i][j];
			if (city[i][j] == 1)
				home.push_back({ i, j });
			else if (city[i][j] == 2)
				chicken.push_back({ i, j });
		}
	}

	vector<int> brute(chicken.size(), 1);

	fill(brute.begin(), brute.begin() + chicken.size() - m, 0);
	int mn = 0x7f7f7f7f7f;
	do {
		int dist = 0;
		for (auto h : home) {
			int tmp = 0x7f7f7f7f;
			for (int i = 0; i < chicken.size(); i++) {
				
				if (brute[i] == 0) continue;

				int x, y;
				tie(x, y) = chicken[i];
				tmp = min(tmp, abs(h.first - x) + abs(h.second - y));
			}
			dist += tmp;
		}
		mn = min(mn, dist);
	} while (next_permutation(brute.begin(), brute.end()));

	cout << mn;
}