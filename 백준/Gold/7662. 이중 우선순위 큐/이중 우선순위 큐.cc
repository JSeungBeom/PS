#include <bits/stdc++.h>

using namespace std;

char c;
int t, k, n;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> k;
		multiset<int> s;
		while (k--) {
			cin >> c >> n;

			if (c == 'I') {
				s.insert(n);
			}
			else {
				if (n == 1) {
					if (!s.empty()) {
						auto it = s.end();
						it--;
						s.erase(it);
					}
				}
				else {
					if(!s.empty())
					s.erase(s.begin());
				}
			}
		}

		if (s.empty()) cout << "EMPTY" << "\n";
		else {
			auto it = s.end(); it--;
			cout << *it << " " << *s.begin() << "\n";
		}
	}

}