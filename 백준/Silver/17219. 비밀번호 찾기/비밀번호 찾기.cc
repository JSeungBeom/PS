#include <bits/stdc++.h>

using namespace std;

int n, m;
string id, pwd;
map<string, string> sites;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	while (n--) {
		cin >> id >> pwd;
		sites.insert({ id, pwd });
	}

	while (m--) {
		cin >> id;
		cout << sites.find(id)->second << "\n";
		
	}
}