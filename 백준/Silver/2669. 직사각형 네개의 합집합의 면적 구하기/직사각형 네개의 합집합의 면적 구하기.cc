#include <bits/stdc++.h>

using namespace std;

int area[102][102];
int sz;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int x1, y1, x2, y2;

	for (int i = 0; i < 4; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int a = x1; a < x2; a++) {
			for (int b = y1; b < y2; b++) {
				if (area[a][b] == 0) {
					area[a][b] = 1; sz++;
				}
			}
		}
	}


	cout << sz;

}