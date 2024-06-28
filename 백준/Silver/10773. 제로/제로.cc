#include <bits/stdc++.h>

using namespace std;

int k;
stack<int> st;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> k;
	int num;

	while (k--) {
		cin >> num;

		if (num == 0)
			st.pop();
		else
			st.push(num);
	}
	int answer = 0;
	while (!st.empty()) {
		answer += st.top(); st.pop();
	}

	cout << answer;
}