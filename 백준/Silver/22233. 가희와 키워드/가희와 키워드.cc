#include <bits/stdc++.h>
#include <unordered_set>
#define X first
#define Y second

using namespace std;

int n, m;
unordered_set<string> us;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	
	string s;

	for (int i = 0; i < n; i++) {
		cin >> s;

		us.insert(s);
	}

	for (int i = 0; i < m; i++) {
		cin >> s;

		string tmp = "";

		for (int j = 0; j < s.length(); j++) {
			if (s[j] != ',')
				tmp += s[j];
			else {
				if (us.find(tmp) != us.end()) {
					us.erase(tmp);
				}

				tmp = "";
			}

			if (j == s.length() - 1) {
				if (us.find(tmp) != us.end()) {
					us.erase(tmp);
				}
			}
		}

		cout << us.size() << '\n';
	}


}