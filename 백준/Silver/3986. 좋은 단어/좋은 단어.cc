#include <bits/stdc++.h>	

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int cnt = 0;
	while (n--) {
		string s;
		cin >> s;
		stack<char> word;
		word.push(s[0]);
		for (int i = 1; i < s.length(); i++) {
			if (!word.empty() && s[i] == word.top()) {
				word.pop();
			}
			else {
				word.push(s[i]);
			}
		}

		if (word.empty()) {
			cnt++;
		}
	}

	cout << cnt;
}