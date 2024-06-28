#include <bits/stdc++.h>
using namespace std;

queue<int> q;
int N;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	string com;
	int x;

	while (N--) {
		cin >> com;

		if (com == "push") {
			cin >> x;
			q.push(x);
		}
		else if (com == "pop") {
			if (q.empty())
				cout << -1 << '\n';
			else {
				cout << q.front() << '\n'; 
				q.pop();
			}
		}
		else if (com == "size") {
			cout << q.size() << '\n';
		}
		else if (com == "empty") {
			cout << q.empty() << '\n';
		}
		else if (com == "front") {
			if (q.empty())
				cout << -1 << '\n';
			else {
				cout << q.front() << '\n';
			}
		}
		else {
			if (q.empty())
				cout << -1 << '\n';
			else {
				cout << q.back() << '\n';
			}
		}
	}
}