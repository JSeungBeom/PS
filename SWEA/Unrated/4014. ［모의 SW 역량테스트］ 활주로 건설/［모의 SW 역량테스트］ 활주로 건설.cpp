#include<iostream>
using namespace std;

int N, X;
int board[25][25];

bool check_w(int x) {
	int cur = board[x][0];
	bool is_hill[25] = { 0 };

	int cnt = 1;

	for (int i = 1; i < N; i++) {
		if (cur < board[x][i]) {
			if (cnt < X) return 0;

			if (abs(cur - board[x][i]) != 1) return 0;


			for (int j = 1; j <= X; j++) {
				is_hill[i - j] = 1;
			}

			cnt = 0;
		}
		else if (cur > board[x][i]) {
			cnt = 0;
		}

		cnt++;
		cur = board[x][i];
	}

	cnt = 1;
	cur = board[x][N - 1];

	for (int i = N - 2; i >= 0; i--) {
		if (cur < board[x][i]) {
			if (cnt < X) return 0;

			if (abs(cur - board[x][i]) != 1) return 0;

			for (int j = 1; j <= X; j++) {
				if (is_hill[i + j])
					return 0;
			}

			cnt = 0;
		}
		else if (cur > board[x][i]) {
			cnt = 0;
		}

		cnt++;
		cur = board[x][i];
	}

	return 1;
}

bool check_h(int y) {
	int cur = board[0][y];
	bool is_hill[25] = { 0 };

	int cnt = 1;

	for (int i = 1; i < N; i++) {
		if (cur < board[i][y]) {
			if (cnt < X) return 0;

			if (abs(cur - board[i][y]) != 1) return 0;

			for (int j = 1; j <= X; j++) {
				is_hill[i - j] = 1;
			}

			cnt = 0;
		}
		else if (cur > board[i][y]) {
			cnt = 0;
		}

		cnt++;
		cur = board[i][y];
	}


	cnt = 1;
	cur = board[N - 1][y];

	for (int i = N - 2; i >= 0; i--) {
		if (cur < board[i][y]) {
			if (cnt < X) return 0;

			for (int j = 1; j <= X; j++) {
				if (is_hill[i + j])
					return 0;
			}

			if (abs(cur - board[i][y]) != 1) return 0;

			cnt = 0;
		}
		else if (cur > board[i][y]) {
			cnt = 0;
		}

		cnt++;
		cur = board[i][y];
	}

	return 1;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> X;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> board[i][j];
			}
		}

		int ans = 0;

		for (int i = 0; i < N; i++) {
			ans += check_w(i);
			ans += check_h(i);
		}

		cout << "#" << test_case << " ";
		cout << ans << '\n';
	}
	return 0;
}