#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int t, n, m;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	int num;

	while (t--) {
		cin >> n >> m;
		
		vector<pair<int, int>> arr = {};
		int cnt = 0;
		int sum = 0;
		int maxval = 0;

		for (int i = 0; i < n; i++) {
			cin >> num;
			arr.push_back({ num, 0 });
		}

		for (int i = 0; i < m; i++) {
			cin >> num;
			arr.push_back({ num, 1 });
		}

		sort(arr.begin(), arr.end());

		for (int i = 0; i < n + m; i++) {

			if (arr[i].Y) {
				cnt++;
				maxval = arr[i].X;
			}

			if (i != 0 && !arr[i].Y && arr[i].X > maxval) {
				sum += cnt;
			}
		}

		cout << sum << "\n";
		arr.clear();
	}
}

// 1 1 1 3 3 3 6 7 8
// 0 0 1 0 0 1 1 0 0