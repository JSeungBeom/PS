#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int T;
int n, k, t, m;
int id, prob, score;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
		
	cin >> T;
	int s, sub, tmp;

	while (T--) {
		cin >> n >> k >> t >> m;

		int arr[105][105] = { 0 };
		int cnt[105] = { 0 };
		int order[105] = { 0 };

		for (int i = 0; i < m; i++) {
			cin >> id >> prob >> score;

			arr[id][prob] = max(arr[id][prob], score);
			cnt[id]++;
			order[id] = i;
		}

		vector<pair<int, pair<int, pair<int, int>>>> v;

		for (int i = 1; i <= n; i++) {
			int tot = 0;
			for (int j = 1; j <= k; j++)
				tot += arr[i][j];

			v.push_back({ -tot, {cnt[i], {order[i], i}} });
		}

		sort(v.begin(), v.end());

		for (int i = 0; i < n; i++) {
			if (v[i].Y.Y.Y == t) cout << i + 1 << '\n';
		}
	}
}