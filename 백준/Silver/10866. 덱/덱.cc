#include <bits/stdc++.h>

using namespace std;

int N, x;
string com;
deque<int> dq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	while (N--) {
		cin >> com;

		if (com == "push_front") {
			cin >> x;
			dq.push_front(x);
		}
		else if (com == "push_back") {
			cin >> x;
			dq.push_back(x);
		}
		else if (com == "pop_front") {
			if (dq.empty())
				cout << -1 << '\n';
			else {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else if (com == "pop_back") {
			if (dq.empty())
				cout << -1 << '\n';
			else {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		else if (com == "size") {
			cout << dq.size() << '\n';
		}
		else if (com == "empty") {
			cout << dq.empty() << '\n';
		}
		else if (com == "front") {
			if (dq.empty())
				cout << -1 << '\n';
			else {
				cout << dq.front() << '\n';
			}
		}
		else {
			if (dq.empty())
				cout << -1 << '\n';
			else {
				cout << dq.back() << '\n';
			}
		}
	}
}