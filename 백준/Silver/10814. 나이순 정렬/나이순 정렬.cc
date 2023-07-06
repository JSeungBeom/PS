#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<int, string>> person;

bool compare(pair<int, string> a, pair<int, string> b) {
	return a.first < b.first;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	int age;
	string name;

	for (int i = 0; i < N; i++) {
		cin >> age >> name;
		person.push_back({ age, name });
	}

	stable_sort(person.begin(), person.end(), compare);

	for (auto e : person) cout << e.first << ' ' << e.second << '\n';
}