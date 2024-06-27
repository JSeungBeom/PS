#include <bits/stdc++.h>
using namespace std;

int alpha[26];

string s;

int main(void) {
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		alpha[s[i] - 'a']++;
	}

	for (auto e : alpha) {
		cout << e << ' ';
	}
}