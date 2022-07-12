#include <bits/stdc++.h>	

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);	
	
	string s1, s2;
	cin >> s1 >> s2;

	int a1[1001] = {};
	int a2[1001] = {};
	int cnt = 0;

	for (auto e : s1) {
		a1[e - 'a']++;
	}

	for (auto e : s2) {
		a2[e - 'a']++;
	}

	for (int i = 0; i < 1001; i++) {
		if (a1[i] != a2[i]) {
			cnt += abs(a1[i] - a2[i]);
		}
	}

	cout << cnt;
}