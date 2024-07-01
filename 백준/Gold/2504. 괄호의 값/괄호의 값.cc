#include <bits/stdc++.h>

using namespace std;

string s;
stack<char> st;
int ans;
int num = 1;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			st.push('(');
			num *= 2;
		}
		else if (s[i] == '[') {
			st.push('[');
			num *= 3;
		}
		else if (s[i] == ')') {
			if (st.empty() || st.top() != '(') {
				cout << 0; return 0;
			}

			if (s[i - 1] == '(') {
				ans += num;
				num /= 2;
				st.pop();
			}
			else {
				num /= 2;
				st.pop();
			}
		}
		else {
			if (st.empty() || st.top() != '[') {
				cout << 0; return 0;
			}

			if (s[i - 1] == '[') {
				ans += num;
				num /= 3;
				st.pop();
			}
			else {
				num /= 3;
				st.pop();
			}
		}
	}

	if (!st.empty()) {
		cout << 0; return 0;
	}
	else {
		cout << ans;
	}
}    