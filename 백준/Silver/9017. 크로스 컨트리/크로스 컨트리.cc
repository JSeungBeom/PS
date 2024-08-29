#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

const int MX = 0x7fffffff;
int t, n;
int cnt[205];
int vis[205];
int sum[205][2];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--) {
		cin >> n;

		fill(cnt, cnt + 201, 0);
		fill(vis, vis + 201, 0);
		for(int i = 1; i <= 200; i++)
			fill(sum[i], sum[i] + 2, 0);
		vector<int> v;

		int team;

		for (int i = 1; i <= n; i++) {
			cin >> team;

			v.push_back(team);

			vis[team]++;
		}

		int sc = 1;

		for (auto e : v) {
			if (vis[e] == 6) {
				cnt[e]++;

				if (cnt[e] == 5)
					sum[e][1] = sc;
				else if (cnt[e] < 5)
					sum[e][0] += sc;

				sc++;
			}
		}

		int ans = 1;
		int mn = MX;

		for (int i = 1; i <= 200; i++) {
			if (vis[i] != 6) continue;
			if (sum[i][0] < mn){
				mn = sum[i][0];
				ans = i;
			}
			else if (sum[i][0] == mn) {
				if (sum[i][1] < sum[ans][1]){
					ans = i;
				}
			}
		}

		cout << ans << '\n';
	}
}