#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int m, n, l;
int x, y;
int shooter[100003];
vector<pair<int, int>> animals;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n >> l;

	for (int i = 0; i < m; i++) {
		cin >> shooter[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		animals.push_back({ x, y });
	}

	sort(shooter, shooter + m);

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		int st = 0; 
		int en = m - 1;

		while (st <= en) {	
			int mid = (st + en) / 2;
			int distance = abs(shooter[mid] - animals[i].X) + animals[i].Y;

			if (distance > l) {
				if (animals[i].X > shooter[mid])
					st = mid + 1;
				else
					en = mid - 1;
			}
			else {
				cnt++;
				break;
			}

		}
	}

	cout << cnt;
}