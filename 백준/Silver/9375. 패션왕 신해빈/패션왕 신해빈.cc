#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int t, n;
string name, type;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--) {
		unordered_map<string, int> clothes;
		int ans = 1;
		cin >> n;
		while (n--) {
			cin >> name >> type;
			clothes[type]++;
		}

		for (auto e : clothes) {
			ans *= e.second + 1;
		}
		cout << ans - 1 << "\n";
	}


}

