#include <bits/stdc++.h>

using namespace std;

string s;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;

	sort(s.begin(), s.end());
	reverse(s.begin(), s.end());

	cout << s;
}