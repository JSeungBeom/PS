#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		list<char> key;

		list<char>::iterator p = key.end();

		string s;
		cin >> s;

		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '<') {
				if (p != key.begin()) {
					p--;
				}
			}
			else if (s[i] == '>') {
				if (p != key.end()) {
					p++;
				}
			}
			else if (s[i] == '-') {
				if (p != key.begin()) {
					p--;
					p = key.erase(p);
				}
			}
			else {
				key.insert(p, s[i]);
			}
		}

		for (char e : key) {
			cout << e;
		}
		cout << "\n";
	}


}