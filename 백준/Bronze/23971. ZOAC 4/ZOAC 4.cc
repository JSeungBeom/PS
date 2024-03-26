#include <bits/stdc++.h>

using namespace std;

int h, w, n, m;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> h >> w >> n >> m;

	int row, col;

	if (w % (m + 1) == 0)
		row = (w / (m + 1));
	else
		row = (w / (m + 1)) + 1;

	if (h % (n + 1) == 0)
		col = (h  /( n + 1));
	else
		col = (h / (n + 1)) + 1;

	cout << row * col;

}