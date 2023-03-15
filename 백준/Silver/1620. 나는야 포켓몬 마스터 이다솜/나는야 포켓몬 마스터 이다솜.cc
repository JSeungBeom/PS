#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int n, m;
string name;
string a1[100005];
unordered_map<string, int> a2;
string question;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> a1[i];
		a2[a1[i]] = i;
	}

	while (m--) {
		cin >> question;
		if (isdigit(question[0])) {
			cout << a1[stoi(question)] << "\n";
		}
		else
			cout << a2[question] << "\n";
	}


}