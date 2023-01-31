#include <bits/stdc++.h>

using namespace std;

string s;
int a[1000003];
vector<int> arr;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		a[i] = s[i] - '0';
	}

	int bits = a[0];
	arr.push_back(a[0]);

	for (int i = 0; i < s.length(); i++) {
		if (a[i] != bits) {
			arr.push_back(a[i]);
			bits = a[i];
		}
	}

	int ans1 = 0;
	int ans2 = 0;

	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == 0)
			ans1++;
		if (arr[i] == 1)
			ans2++;
	}

	cout << min(ans1, ans2);
}