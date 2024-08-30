#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n, m;
map<string, int> scnt;
vector<string> v;

bool cmp(const string &a, const string &b) {
	if (scnt[a] == scnt[b]) {
		if (a.length() == b.length()) {
			return a < b;
		}

		return a.length() > b.length();
	}

	return scnt[a] > scnt[b];
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	
	cin >> n >> m;

	string s;

	for (int i = 0; i < n; i++) {
		cin >> s;

		if (s.length() < m) continue;

		if (scnt[s] == 0)
			v.push_back(s);

		scnt[s]++;
	}

	sort(v.begin(), v.end(), cmp);

	for (auto e : v) {
		cout << e << '\n';
	}

}