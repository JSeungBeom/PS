#include <bits/stdc++.h>

using namespace std;

int L;
string s;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> L;
	cin >> s;

	int H = 0;

	for (int i = 0; i < L; i++) {
		H += ((s[i] - 'a' + 1) * (int)pow(31, i)) % 1234567891;
	}

	cout << H;
}