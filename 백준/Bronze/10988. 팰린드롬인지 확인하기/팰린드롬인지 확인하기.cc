#include <bits/stdc++.h>

using namespace std;
string s;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	string tmp = s;
	reverse(s.begin(), s.end());
	if (tmp == s) cout << 1;
	else cout << 0;
}