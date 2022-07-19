#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	deque<int> d;

	int n;
	cin >> n;

	while (n--) {
		string s;
		cin >> s;

		int x;

		if (s == "push_front") {
			cin >> x;
			d.push_front(x);
		}
		else if (s == "push_back") {
			cin >> x;
			d.push_back(x);
		}
		else if (s == "pop_front") {
			if (d.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << d.front() << "\n";
				d.pop_front();
			}
		}
		else if (s == "pop_back") {
			if (d.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << d.back() << "\n";
				d.pop_back();
			}
		}
		else if (s == "size") {
			cout << d.size() << "\n";
		}
		else if (s == "empty") {
			if (d.empty()) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
		else if (s == "front") {
			if (d.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << d.front() << "\n";
			}
		}
		else{
			if (d.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << d.back() << "\n";
			}
		}
	}
}