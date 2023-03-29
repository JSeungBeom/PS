#include <bits/stdc++.h>

using namespace std;

int n, p, l, g, m, x;

string s;

pair<int, int> diffidx[100002];
set<int> probdiff[102];
set<int> probidxdiff[102][102];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> p >> l >> g;
		diffidx[p] = { l, g };
		probdiff[l].insert(p);
		probidxdiff[g][l].insert(p);
	}
	cin >> m;
	while (m--) {
		cin >> s;
		if (s == "recommend") {
			cin >> g >> x;
			if (x == 1) {
				for (int i = 100; i >= 1; i--) {
					if (!probidxdiff[g][i].empty()) {
						cout << *prev(probidxdiff[g][i].end()) << "\n"; break;
					}
				}
			}
			else {
				for (int i = 1; i <= 100; i++) {
					if (!probidxdiff[g][i].empty()) {
						cout << *probidxdiff[g][i].begin() << "\n"; break;
					}
				}
			}
		}
		else if (s == "recommend2") {
			cin >> x;
			if (x == 1) {
				for (int i = 100; i >= 1; i--) {
					if (!probdiff[i].empty()) {
						cout << *prev(probdiff[i].end()) << "\n"; break;
					}
				}
			}
			else {
				for (int i = 1; i <= 100; i++) {
					if (!probdiff[i].empty()) {
						cout << *probdiff[i].begin() << "\n"; break;
					}
				}
			}
		}
		else if (s == "recommend3") {
			cin >> x >> l;
			int ans = -1;
			if (x == 1) {
				for (int i = l; i <= 100; i++) {
					if (!probdiff[i].empty()) {
						ans = *probdiff[i].begin(); break;
					}
				}
			}
			else {
				for (int i = l - 1; i >= 1; i--) {
					if (!probdiff[i].empty()) {
						ans = *prev(probdiff[i].end()); break;
					}
				}
			}

			cout << ans << "\n";
		}
		if (s == "add") {
			cin >> p >> l >> g;
			diffidx[p] = { l, g };
			probdiff[l].insert(p);
			probidxdiff[g][l].insert(p);
		}
		if (s == "solved") {
			cin >> p;
			int a, b;
			tie(a, b) = diffidx[p];
			probdiff[a].erase(p);
			probidxdiff[b][a].erase(p);
		}
	}
}