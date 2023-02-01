#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n,x,y;
vector<pair<int, int>> line;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		line.push_back({x, y});
	}

	sort(line.begin(), line.end());

	long long ans = 0;
	int st = line[0].X;
	int en = line[0].Y;

	for (int i = 1; i < n; i++) {
		if (line[i].X <= en && line[i].Y > en)
			en = line[i].Y;
		else if(line[i].X > en) {
			ans += en - st;
			st = line[i].X;
			en = line[i].Y;
		}
	}

	ans += en - st;
	cout << ans;
}