#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n, c;
vector<pair<int, int>> arr;

bool cmp(pair<int,int> a, pair<int, int> b) {
	return a.X > b.X;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> c;
	int num;

	for (int i = 0; i < n; i++) {
		cin >> num;
		
		bool chk = 0;

		for (auto& a : arr) {
			if (a.Y == num) {
				a.X++;
				chk = 1;
			}
		}

		if(!chk)
		arr.push_back({ 1, num });
	}

	stable_sort(arr.begin(), arr.end(), cmp);

	for (auto e : arr) {
		while (e.X--) {
			cout << e.Y << " ";
		}
	}

}