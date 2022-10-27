#include <bits/stdc++.h>

using namespace std;

string serial[52];

bool cmp(const string &a, const string &b) {
	if (a.length() != b.length()) {
		return a.length() < b.length();
	}
	else {
		int sum1 = 0;
		int sum2 = 0;
		for (int i = 0; i < a.length(); i++) {
			if (0 <= a[i] - '0' && a[i] - '0' < 10) {
				sum1 += a[i] - '0';
			}
			if (0 <= b[i] - '0' && b[i] - '0' < 10) {
				sum2 += b[i] - '0';
			}
		}

		if(sum1 != sum2)
		return sum1 < sum2;
		return a < b;
	}
	
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	string s;
	for(int i =0 ; i < n; i ++){
		cin >> s;
		serial[i] = s;
	}

	sort(serial, serial + n, cmp);

	for (int i = 0; i < n; i++) {
		cout << serial[i] << "\n";
	}
}