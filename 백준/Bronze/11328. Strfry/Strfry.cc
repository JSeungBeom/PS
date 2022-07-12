#include <bits/stdc++.h>	

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);	

	int n;
	cin >> n;


	while (n--) {
		int alpha[26] = {};
		bool flag = false;
		string s;
		cin >> s;
		for (auto e : s) {
			alpha[e - 'a']++;
		}

		cin >> s;
		for (auto e : s) {
			alpha[e - 'a']--;
		}

		for (auto e : alpha) {
			if (e != 0) {
				flag = true;
				cout << "Impossible\n";
				break;
			}
		}
		
		if (!flag) {
			cout << "Possible\n";
		}
	}

}