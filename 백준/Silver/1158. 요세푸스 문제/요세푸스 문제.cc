#include <bits/stdc++.h>

using namespace std;
int n, k;
list<int> l;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		l.push_back(i);
	}

	auto it = l.begin();
	cout << "<";
	while (!l.empty()) {
		for (int i = 0; i < k - 1; i++) {
			if (it == l.end()) {
				it = l.begin(); it++;
			}
			else
				it++;
		}
		if (it == l.end())
			it = l.begin();
		if (l.size() > 1)
			cout << *it << ", ";
		else
			cout << *it;
		it = l.erase(it);
	}
	cout << ">";


}