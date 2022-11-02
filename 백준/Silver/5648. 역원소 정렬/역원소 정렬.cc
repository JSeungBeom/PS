#include <bits/stdc++.h>

using namespace std;

int n;
vector<long long> arr;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		reverse(s.begin(), s.end());
		arr.push_back(stoll(s));
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\n";
	}

}