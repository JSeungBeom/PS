#include <bits/stdc++.h>

using namespace std;

deque<int> d;
int x, com, n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	while (n--) {
		cin >> com;
		switch (com) {
		case 1:
			cin >> x;
			d.push_front(x);
			break;
		case 2:
			cin >> x;
			d.push_back(x);
			break;
		case 3:
			if (!d.empty()) {
				cout << d.front() << '\n';
				d.pop_front();
			}
			else
				cout << -1 << '\n';
			break;
		case 4: 
			if (!d.empty()) {
				cout << d.back() << '\n';
				d.pop_back();
			}
			else
				cout << -1 << '\n';
			break;
		case 5:
			cout << d.size() << '\n';
			break;
		case 6:
			if (d.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
			break;
		case 7:
			if (!d.empty())
				cout << d.front() << '\n';
			else
				cout << -1 << '\n';
			break;
		default:
			if (!d.empty())
				cout << d.back() << '\n';
			else
				cout << -1 << '\n';
			break;
		}
	}
}