#include <iostream>
#include <deque>
using namespace std;

int K;
int num, dir;

void rotate(deque<int> magnet[], int num, int dir) {
	if (dir == 1) {
		magnet[num].push_front(magnet[num].back());
		magnet[num].pop_back();
	}
	else {
		magnet[num].push_back(magnet[num].front());
		magnet[num].pop_front();
	}
}

int get_score(deque<int> magnet[]) {
	int ans = 0;
	int mul = 1;
	for (int i = 0; i < 4; i++) {
		if (magnet[i][0])
			ans += mul;

		mul *= 2;
	}

	return ans;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> K;

		deque<int> magnet[4];

		int n;

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> n;
				magnet[i].push_back(n);
			}
		}

		for (int i = 0; i < K; i++) {
			cin >> num >> dir;

			int rot[4] = { 0 };
			rot[num - 1] = dir;

			for (int j = num; j < 4; j++) {
				if (magnet[j][6] != magnet[j - 1][2])
					rot[j] = -rot[j - 1];
			}

			for (int j = num - 2; j >= 0; j--) {
				if (magnet[j][2] != magnet[j + 1][6])
					rot[j] = -rot[j + 1];
			}

			for (int i = 0; i < 4; i++) {
				if (rot[i] != 0)
					rotate(magnet, i, rot[i]);
			}
		}

		cout << "#" << test_case << " ";
		cout << get_score(magnet) << '\n';
	}
	return 0;
}