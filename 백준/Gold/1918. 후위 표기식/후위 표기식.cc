#include <bits/stdc++.h>

using namespace std;

string s;
stack<char> st;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		if ('A' <= s[i] && s[i] <= 'Z')
			cout << s[i];
		else if (s[i] == '(')
			st.push(s[i]);
		else if (s[i] == '*' || s[i] == '/') {
			while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
				cout << st.top(); st.pop();
			}
			st.push(s[i]);
		}
		else if (s[i] == '+' || s[i] == '-') {
			while (!st.empty() && (st.top() == '*' || st.top() == '/'
				|| st.top() == '+' || st.top()  == '-')) {
				cout << st.top(); st.pop();
			}
			st.push(s[i]);
		}
		else if (s[i] == ')') {
			while (!st.empty() && st.top() != '(') {
				cout << st.top(); st.pop();
			}

			st.pop();
		}
	}

	while (!st.empty()) {
		cout << st.top(); st.pop();
	}

}