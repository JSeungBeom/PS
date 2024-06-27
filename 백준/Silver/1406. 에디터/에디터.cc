#include <bits/stdc++.h>

using namespace std;

list<char> l;

string s;
int M;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		l.push_back(s[i]);
	}

	cin >> M;
	auto it = l.end(); 
	char com;
	char c;
	while (M--) {
		cin >> com;

		switch (com) {
		case 'L':
			if (it != l.begin()) {
				it--;
				break;
			}
			break;
		case 'D':
			if (it != l.end()) {
				it++;
				break;
			}
			break;
		case 'B':
			if (it != l.begin()) {
				it--;
				it = l.erase(it);
				break;
			}
			break;
		case 'P':
			cin >> c;
			l.insert(it, c);
			break;
		}
	}
	
	for (auto e : l)
		cout << e;
}