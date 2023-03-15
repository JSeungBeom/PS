#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

string person, check;
int n;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	unordered_set<string> people;
	while (n--) {
		cin >> person >> check;
		if (check == "enter") people.insert(person);
		else people.erase(person);
	}

	vector<string> tmp(people.begin(), people.end());
	sort(tmp.begin(), tmp.end(), greater<string>());

	for (string s : tmp) cout << s << "\n";
}