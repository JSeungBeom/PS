#include <bits/stdc++.h>	

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	

	string s;
	while (getline(cin, s)) {
		if (s == ".") {
			break;
		}

		stack<char> par;

		int flag = false;

		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(' || s[i] == '[') {
				par.push(s[i]);
			} 
			else if (s[i] == ')') {
				if (!par.empty() && par.top() == '(') {
					par.pop();
				}
				else {
					flag = true;
				}
			}
			else if (s[i] == ']') {
				if (!par.empty() && par.top() == '[') {
					par.pop();
				}
				else {
					flag = true;
				}
			}
		}


		if (!par.empty() || flag) {
			cout << "no\n";
		}
		else {
			cout << "yes\n";
		}
	}

}