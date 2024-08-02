#include <bits/stdc++.h>
#define X first
#define Y second

#define INF 0x3f3f3f3f

using namespace std;

int n, m, k;
int dist[205][205];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		fill(dist[i], dist[i] + n + 1, INF);
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;

		dist[a][b] = min(dist[a][b], c);
	}

	for (int i = 1; i <= n; i++) {
		dist[i][i] = 0;
	}

	for (int mid = 1; mid <= n; mid++) {
		for (int st = 1; st <= n; st++) {
			for (int en = 1; en <= n; en++) {
				dist[st][en] = min(dist[st][en],
					dist[st][mid] + dist[mid][en]);
			}
		}
	}

	cin >> k;

	vector<int> friends;

	int town;

	for (int i = 0; i < k; i++) {
		cin >> town;
		friends.push_back(town);
	}

	int mn = 0x7f7f7f7f;

	for (int i = 1; i <= n; i++) {
		int mx = 0;
		for (auto city : friends) {
			mx = max(mx, dist[city][i] + dist[i][city]);
		}
		mn = min(mx, mn);
	}

	for (int i = 1; i <= n; i++) {
		int mx = 0;
		for (auto city : friends) {
			mx = max(mx, dist[city][i] + dist[i][city]);
		}
		if (mx == mn)
			cout << i << ' ';
	}


}