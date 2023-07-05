#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		cin >> s;
		if (s == "0") return 0;
		string tmp = s;
		reverse(s.begin(), s.end());
		if (tmp == s) cout << "yes\n";
		else cout << "no\n";
	}
}