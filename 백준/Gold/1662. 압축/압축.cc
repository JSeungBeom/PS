#include <vector>
#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<int> result;
string s;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			result.push(-1);
		}
		else if (s[i] == ')') {
			int cnt = 0;

			while (result.top() != -1) {
				cnt += result.top();
				result.pop();
			}

			result.pop();
			int rep = result.top(); result.pop();

			result.push(rep * cnt);
		}
		else {
			if (s[i + 1] == '(')
				result.push(s[i] - '0');
			else
				result.push(1);
		}
	}

	int ans = 0;

	while (!result.empty()) {
		ans += result.top(); result.pop();
	}

	cout << ans;
}