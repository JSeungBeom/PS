#include <bits/stdc++.h>

using namespace std;

int n;
char com;

string s;

set<string> st;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> com;

	for (int i = 0; i < n; i++) {
		cin >> s;

		st.insert(s);
	}

	if (com == 'Y')
		cout << st.size();
	else if (com == 'F')
		cout << st.size() / 2;
	else
		cout << st.size() / 3;


}
