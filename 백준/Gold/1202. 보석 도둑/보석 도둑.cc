#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n, k;
long long ans;
vector<pair<int, int>> jewely;
multiset<int> bag;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int m, v;
		cin >> m >> v;
		jewely.push_back({ v, m });
	}

	for (int i = 0; i < k; i++) {
		int c;
		cin >> c;
		bag.insert(c);
	}

	sort(jewely.begin(), jewely.end());

	for (int i = n - 1; i >= 0; i--) {
		int m, v;
		tie(v, m) = jewely[i];
		auto it = bag.lower_bound(m);
		if (it == bag.end()) continue;
		ans += v;
		bag.erase(it);
	}

	cout << ans;
	
}