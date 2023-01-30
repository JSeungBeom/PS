#include <bits/stdc++.h>

using namespace std;

int n;
int sm, sd, em, ed;
vector<pair<int, int>> flower;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	
	for(int i = 0; i < n; i++){
		cin >> sm >> sd >> em >> ed;
		flower.push_back({ sm * 100 + sd, em * 100 + ed });
	}

	int t = 301;
	int ans = 0;

	while (t < 1201) {
		int nxt = t;
		for (int i = 0; i < n; i++) {
			if (flower[i].first <= t && flower[i].second > nxt)
				nxt = flower[i].second;
		}

		if (nxt == t) {
			cout << 0;
			return 0;
		}

		ans++;
		t = nxt;
	}

	cout << ans;
}