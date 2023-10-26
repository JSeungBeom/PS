#include <bits/stdc++.h>

using namespace std;

string s, c;
deque<char> dq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	cin >> c;

	for (int i = 0; i < s.length(); i++) {
		dq.push_back(s[i]);
		
		if (s[i] == c.back()) {
			bool chk = 0;

			if (dq.size() < c.length())
				continue;
			else {
				for (int i = 0; i < c.length(); i++) {
					if (dq[dq.size() - c.length() + i] != c[i]) {
						chk = 1;
						break;
					}
				}
			}

			if (!chk) {
				for (int i = 0; i < c.length(); i++) {
					dq.pop_back();
				}
			}
		}

	}


	if (dq.empty()) {
		cout << "FRULA";
	}
	else {
		while (!dq.empty()) {
			char c = dq.front(); dq.pop_front();
			cout << c;
		}
	}
}