#include <bits/stdc++.h>	

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	stack<int> bracket;

	int sum = 0;
	int num = 1;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			bracket.push(s[i]);
			num *= 2;
		}
		else if (s[i] == '[') {
			bracket.push(s[i]);
			num *= 3;
		}
		else if (s[i] == ')'){
			if (bracket.empty() || bracket.top() != '(') {
				cout << 0;
				return 0;
			}

			if (s[i - 1] == '(') {
				sum += num;
				bracket.pop();
				num /= 2;
			}
			else {
				bracket.pop();
				num /= 2;
			}
		}
		else {
			if (bracket.empty() || bracket.top() != '[') {
				cout << 0;
				return 0;
			}
			
			if (s[i - 1] == '[') {
				sum += num;
				bracket.pop();
				num /= 3;
			}
			else {
				bracket.pop();
				num /= 3;
			}
		}
	}

	if (bracket.empty()) {
		cout << sum;
	}
	else
		cout << 0;

}