#include <bits/stdc++.h>	

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	int result = 0;

	stack<int> stick;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			stick.push(s[i]);
		}
		else if (s[i] == ')') {
			if (s[i - 1] == '(') {
				stick.pop();
				result += stick.size();
			}
			else {
				stick.pop();
				result++;
			}
		}
	}

	cout << result;
}