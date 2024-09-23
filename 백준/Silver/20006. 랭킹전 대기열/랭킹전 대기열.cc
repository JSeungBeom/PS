#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int p, m, l;
string n;
vector<pair<string, int>> room[305];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> p >> m;

	for (int i = 0; i < p; i++) {
		cin >> l >> n;

		bool flag = 0;

		for (int j = 0; j <= i; j++) {
			if(room[j].size() < m && room[j].size() > 0)
				if (abs(room[j][0].Y - l) <= 10) {
					flag = 1;
					room[j].push_back({ n, l });
					break;
				}
		}

		if (!flag) {
			room[i].push_back({ n ,l });
		}
	}

	for (int i = 0; i < p; i++) {
		if (room[i].size() > 0 && room[i].size() < m)
			cout << "Waiting!\n";
		else if (room[i].size() > 0 && room[i].size() >= m)
			cout << "Started!\n";

		sort(room[i].begin(), room[i].end());

		for (int j = 0; j < room[i].size(); j++) {
			cout << room[i][j].Y << ' '
				<< room[i][j].X << '\n';
		}
	}
}