#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

string s;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;

	int cnt0 = 0;
	int cnt1 = 0;

	vector<int> pos0;
	vector<int> pos1;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '0') {
			cnt0++;
			pos0.push_back(i);
		}
		else {
			cnt1++;
			pos1.push_back(i);
		}
	}

	reverse(pos0.begin(), pos0.end());

	cnt0 /= 2;
	cnt1 /= 2;

	for (auto e : pos0) {
		if (!cnt0) break;

		s[e] = '2';
		cnt0--;
	}

	for (auto e : pos1) {
		if (!cnt1) break;

		s[e] = '2';
		cnt1--;
	}

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '2')
			continue;

		cout << s[i];
	}

}