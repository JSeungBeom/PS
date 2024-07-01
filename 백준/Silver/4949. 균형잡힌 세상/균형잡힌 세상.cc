#include <bits/stdc++.h>

using namespace std;

string s;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		getline(cin, s);

		stack<char> st;
		bool flag = 0;

		if (s == ".")
			return 0;

		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(' || s[i] == '[')
				st.push(s[i]);
			else if (s[i] == ')') {
				if (!st.empty() && st.top() == '(')
					st.pop();
				else {
					flag = 1;
					break;
				}
			}
			else if (s[i] == ']') {
				if (!st.empty() && st.top() == '[')
					st.pop();
				else {
					flag = 1;
					break;
				}
			}
		}

		if (flag || !st.empty()) {
			cout << "no" << '\n';
		}
		else {
			cout << "yes" << '\n';
		}
	}
}