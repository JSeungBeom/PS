#include <bits/stdc++.h>
using namespace std;

stack<int> st;
int n;

int main(void) {
	cin >> n;

	string com;

	while (n--) {
		cin >> com;

		if (com == "push") {
			int x;
			cin >> x;
			st.push(x);
		}
		else if (com == "pop") {
			if (st.empty())
				cout << -1 << '\n';
			else {
				cout << st.top() << '\n';
				st.pop();
			}
		}
		else if (com == "size") {
			cout << st.size() << '\n';
		}
		else if (com == "empty") {
			cout << st.empty() << '\n';
		}
		else {
			if (st.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << st.top() << '\n';
			}
		}
	}
}