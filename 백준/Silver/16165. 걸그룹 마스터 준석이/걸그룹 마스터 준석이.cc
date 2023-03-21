#include <bits/stdc++.h>
#include <unordered_map>
#define X first
#define Y second

using namespace std;

int n, m, num, quest;
string team, name, ans;
unordered_map<string, vector<string>> t2n;
unordered_map<string, string> n2t;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	while (n--) {
		cin >> team >> num;
		while (num--) {
			cin >> name;
			t2n[team].push_back(name);
			n2t[name] = team;
		}

		sort(t2n[team].begin(), t2n[team].end());
	}

	while (m--) {
		cin >> ans >> quest;
		if (quest) cout << n2t[ans] << "\n";
		else {
			for (auto e : t2n[ans]) {
				cout << e << "\n";
			}
		}
	}
}