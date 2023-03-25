#include <bits/stdc++.h>

using namespace std;

int n, p, l, m;
set<int> prob[103];
int diff[100003];
string s;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p >> l;
		prob[l].insert(p);
		diff[p] = l;
	}

	cin >> m;
	while (m--) {
		cin >> s;
		if (s == "recommend") {
			cin >> p;
			if (p == 1) {
				for (int i = 100; i >= 0; i--) {
					if (!prob[i].empty()) {
						cout << *prev(prob[i].end()) << "\n"; break;
					}
				}
			}
			else {
				for (int i = 0; i < 100; i++) {
					if (!prob[i].empty()) {
						cout << *prob[i].begin() << "\n"; break;
					}
				}
			}
		}
		else if (s == "add") {
			cin >> p >> l;
			prob[l].insert(p); diff[p] = l;
		}
		else {
			cin >> p;
			prob[diff[p]].erase(p);
		}
	}

}