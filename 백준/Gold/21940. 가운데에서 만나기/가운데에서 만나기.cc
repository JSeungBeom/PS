#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int n, m;
int a, b, t;
int k, c;
int d[203][203];
int friends[203];
vector<int> city;
set<int> s;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		fill(d[i], d[i] + n + 1, INF);
	}
	while (m--) {
		cin >> a >> b >> t;
		d[a][b] = t;
	}

	cin >> k;
	for (int i = 1; i <= k; i++) {
		cin >> c;
		friends[i] = c;
	}

	for (int i = 1; i <= n; i++) {
		d[i][i] = 0;
	}

	for (int mid = 1; mid <= n; mid++) {
		for (int st = 1; st <= n; st++) {
			for (int en = 1; en <= n; en++) {
				d[st][en] = min(d[st][en], d[st][mid] + d[mid][en]);
			}
		}
	}

	int ans = 0x7f7f7f7f;

	for (int i = 1; i <= n; i++) {
		int mx = 0;
		for (int j = 1; j <= k; j++) {
			mx = max(mx, d[friends[j]][i] + d[i][friends[j]]);
		}
		ans = min(mx, ans);
	}

	for (int i = 1; i <= n; i++) {
		int mx = 0;
		for (int j = 1; j <= k; j++) {
			mx = max(mx, d[friends[j]][i] + d[i][friends[j]]);
		}
		if (mx == ans) s.insert(i);
	}

	vector<int> v(s.begin(), s.end());
	sort(v.begin(), v.end());
	for (auto e : v) {
		cout << e << ' ';
	}
}