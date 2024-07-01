#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	int ans = 0;

	while (n--) {
		cin >> s;
		stack<char> st;

		for (int i = 0; i < s.length(); i++) {
			if (st.empty() || st.top() != s[i])
				st.push(s[i]);
			else
				st.pop();
		}

		if (st.empty())
			ans++;
	}

	cout << ans;

}