#include <bits/stdc++.h>

using namespace std;
int t;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--) {
		list<char> l;
		string s;

		cin >> s;
		auto it = l.begin();
		for (int i = 0; i < s.length(); i++) {
			switch (s[i]) {
			case '<':
				if (it != l.begin())
					it--;
				break;

			case '>':
				if (it != l.end())
					it++;
				break;

			case '-':
				if (it != l.begin()) {
					it--;
					it = l.erase(it);
				}
				break;
			default:
				l.insert(it, s[i]);
				break;
			}

		}

		for (auto e : l)
			cout << e;
		cout << '\n';
	}
}