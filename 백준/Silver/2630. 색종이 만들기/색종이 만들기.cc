#include <bits/stdc++.h>
using namespace std;

int N;
int paper[200][200]; // 색종이
int cnt[2]; // 색종이 개수

bool check(int x, int y, int n) {
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (paper[x][y] != paper[i][j])
				return false;
		}
	}

	return true;
}

void func(int x, int y, int z) {
	if (check(x, y, z)) {
		cnt[paper[x][y]] += 1;
		return;
	}

	int n = z / 2;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			func(x + n * i, y + n * j, n);
		}
	}
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> paper[i][j];
		}
	}

	func(0, 0, N);
	for (int e : cnt) {
		cout << e << "\n";
	}
}