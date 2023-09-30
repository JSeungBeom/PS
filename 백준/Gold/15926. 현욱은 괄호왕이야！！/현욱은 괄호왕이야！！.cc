#include <bits/stdc++.h>

using namespace std;

int n;
string s;
stack<int> st;
int dp[200003];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	cin >> s;

	for (int i = 0; i < n; i++) {
		if (s[i] == '(')
			st.push(i);
		else if (!st.empty() && s[i] == ')') {
			dp[st.top()] = 1;
			dp[i] = 1;
			st.pop();
		}
	}
	int cnt = 0;
	int ans = 0;

	for (int i = 0; i < n; i++) {
		if (dp[i]) cnt++;
		else {
			ans = max(ans, cnt);
			cnt = 0;
		}
	}

	cout << max(ans, cnt);
}