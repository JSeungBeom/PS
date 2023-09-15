#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n, k, x, y;
pair<int, int> pos[52];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		pos[i] = { x, y };
	}

	int mn = 0x7f7f7f7f;

	if (k == 1) {
		for (int i = 0; i < n; i++) {
			int dist = 0;
			for (int j = 0; j < n; j++) {
				dist = max(dist, abs(pos[i].X - pos[j].X) +
					abs(pos[i].Y - pos[j].Y));
			}
			mn = min(dist, mn);
		}
	}


	if (k == 2) {
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				int dist_1 = 0;
				int dist_2 = 0;
				int mx = 0;

				for (int k = 0; k < n; k++) {
					if (k == i || k == j) continue;
					dist_1 = abs(pos[i].X - pos[k].X) +
						abs(pos[i].Y - pos[k].Y);

					dist_2 = abs(pos[j].X - pos[k].X) +
						abs(pos[j].Y - pos[k].Y);


					dist_1 = min(dist_1, dist_2);
					mx = max(mx, dist_1);
				}

				mn = min(mx , mn);
			}
		}
	}

	if (k == 3) {
		for (int i = 0; i < n - 2; i++) {
			for (int j = i + 1; j < n - 1; j++) {
				for (int k = j + 1; k < n; k++) {
					int dist_1 = 0;
					int dist_2 = 0;
					int dist_3 = 0;
					int mx = 0;

					for (int l = 0; l < n; l++) {
						dist_1 = abs(pos[i].X - pos[l].X) +
							abs(pos[i].Y - pos[l].Y);

						dist_2 = abs(pos[j].X - pos[l].X) +
							abs(pos[j].Y - pos[l].Y);

						dist_3 = abs(pos[k].X - pos[l].X) +
							abs(pos[k].Y - pos[l].Y);

						dist_1 = min({dist_1, dist_2, dist_3});
						mx = max(mx, dist_1);
					}
					mn = min(mx, mn);

				}
			}
		}
	}

	cout << mn;
}