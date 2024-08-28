#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n, m;
vector<int> lamp;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int x;

	for (int i = 0; i < m; i++) {
		cin >> x;
		lamp.push_back(x);
	}

	int st = 0;
	int en = n;

	while (st <= en) {
		int mid = (st + en) / 2;
		bool flag = 0;

		if (lamp[0] > mid) flag = 1;

		for (int i = 0; i < m - 1; i++) {
			if (lamp[i + 1] - lamp[i] > mid * 2) {
				flag = 1;
				break;
			}
		}

		if (n - lamp[m - 1] > mid) flag = 1;

		if (!flag) en = mid - 1;
		else st = mid + 1;
	}

	cout << st;

}