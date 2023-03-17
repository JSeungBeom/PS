#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int n, m;
unordered_map<string, string> note;
string site, pwd;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	
	while (n--) {
		cin >> site >> pwd;
		note[site] = pwd;
	}

	while (m--) {
		cin >> site;
		cout << note.find(site)->second << "\n";
	}
}