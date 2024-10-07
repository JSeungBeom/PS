#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int board[20][20];
int tmp[20][20];
int arr[15];
int mn = 0x7fffffff;

int N, W, H;

bool OOB(int x, int y) {
	if (x < 0 || x >= H || y < 0 || y >= W)
		return 1;

	return 0;
}

void explode(int x, int y) {
	if (OOB(x, y) || tmp[x][y] == 0)
		return;

	int range = tmp[x][y];

	tmp[x][y] = 0;

	if (range == 1)
		return;

	for (int i = x + 1; i < x + range; i++) {
		explode(i, y);
	}

	for (int i = x - 1; i > x - range; i--) {
		explode(i, y);
	}

	for (int i = y + 1; i < y + range; i++) {
		explode(x, i);
	}

	for (int i = y - 1; i > y - range; i--) {
		explode(x, i);
	}
}

void find_block(int cur) {
	for (int i = 0; i < H; i++) {
		if (OOB(i, cur))
			return;

		if (tmp[i][cur]) {
			explode(i, cur);
			break;
		}
	}
}

void fall() {
	for (int i = H - 2; i >= 0; i--) {
		for (int j = 0; j < W; j++) {
			if (tmp[i][j]) {
				while (!tmp[i + 1][j] && !OOB(i + 1, j)) {
					tmp[i + 1][j] = tmp[i][j];
					tmp[i][j] = 0;
					i++;
				}
			}
		}
	}
}

int count() {
	int cnt = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (tmp[i][j]) cnt++;
		}
	}

	return cnt;
}

void back_tracking(int n) {
	if (n == N) {
		for (int i = 0; i < n; i++) {
			find_block(arr[i]);
			fall();
		}

		int val = count();

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				tmp[i][j] = board[i][j];
			}
		}

		mn = min(val, mn);

		return;
	}

	for (int i = 0; i < W; i++) {
		arr[n] = i;
		back_tracking(n + 1);
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> W >> H;

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> board[i][j];
				tmp[i][j] = board[i][j];
			}
		}

		back_tracking(0);

		cout << "#" << test_case << ' ';
		cout << mn << '\n';

		mn = 0x7fffffff;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}