#include <bits/stdc++.h>	

using namespace std;

int main() {
	string s;
	cin >> s;

	int alpha[26] = { 0, };

	for (int i = 0; i < s.length(); i++) {
		alpha[s[i] - 97]++;
	}

	for (int e : alpha) {
		cout << e << ' ';
	}
}