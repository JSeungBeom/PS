#include <bits/stdc++.h>

using namespace std;

int n, m;
set<string> s;
vector<string> unknown;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	
	string name;

	while (n--) {
		cin >> name;
		s.insert(name);
	}

	while (m--) {
		cin >> name;
		if (s.find(name) == s.end()) {
			s.insert(name);
		}
		else {
			unknown.push_back(name);
		}
	}

	sort(unknown.begin(), unknown.end());

	cout << unknown.size() << '\n';

	for (auto e : unknown)
		cout << e << '\n';



}