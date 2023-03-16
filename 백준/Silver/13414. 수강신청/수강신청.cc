#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
#define X first
#define Y second

using namespace std;

int k, l;
unordered_map<string, int> chk;

bool compare(pair<string, int> a, pair<string, int> b) {
	return a.Y < b.Y;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> k >> l;

	string id;
	

	for (int i = 0; i < l; i++) {
		cin >> id;
		if (chk.find(id) != chk.end()) {
			chk.erase(id);
			chk[id] = i;
		}
		chk[id] = i;
	}

	vector<pair<string, int>> slist(chk.begin(), chk.end());

	sort(slist.begin(), slist.end(), compare);

	int en = min(k, (int)slist.size());
	for (int i = 0; i < en; i++) {
		cout << slist[i].X << "\n";
	}

	
}