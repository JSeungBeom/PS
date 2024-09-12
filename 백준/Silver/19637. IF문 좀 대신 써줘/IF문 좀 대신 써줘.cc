#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n, m;
vector<int> arr;
vector<string> v;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	string name;
	int val;
	int pre = -1;

	for (int i = 0; i < n; i++) {
		cin >> name >> val;


		if (pre == val)
			continue;

		pre = val;
		arr.push_back(val);
		v.push_back(name);
	}

	int score;

	for (int i = 0; i < m; i++) {
		cin >> score;

		int up = lower_bound(arr.begin(), arr.end(), score) - arr.begin();

		cout << v[up] << '\n';
	}



}