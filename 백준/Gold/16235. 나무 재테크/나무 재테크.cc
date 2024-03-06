#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <deque>

using namespace std;

int n, m, k;

int a[11][11];
int nutri[11][11];
deque<int> trees[11][11];

int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int main() {
	scanf("%d %d %d", &n, &m, &k);

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			scanf("%d", &a[i][j]);
			nutri[i][j] = 5;
		}
	}

	for (int i = 0; i < m; ++i) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		trees[x][y].push_back(z);
	}

	for (int t = 0; t < k; ++t) {
		// 봄
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				int size = trees[i][j].size();
				// 양분 먹고 나이 +1
				int k = 0;
				for (; k < trees[i][j].size(); ++k) {
					if (nutri[i][j] >= trees[i][j][k]) {
						nutri[i][j] -= trees[i][j][k];
						trees[i][j][k]++;
					}
					else {
						break;
					}
				}
				// 여름
				// 죽은 나무 있는 곳 양분 추가
				for (int p = trees[i][j].size() - 1; p >= k; --p) {
					nutri[i][j] += trees[i][j][p] / 2;
					trees[i][j].pop_back();
				}
			}
		}

		// 가을
		// 나무 번식
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (trees[i][j].size() > 0) {
					for (int k = 0; k < trees[i][j].size(); ++k) {
						if (trees[i][j][k] % 5 == 0) {
							for (int q = 0; q < 8; ++q) {
								int nx = i + dx[q];
								int ny = j + dy[q];
								if (nx < 1 || nx > n || ny < 1 || ny > n)
									continue;
								else {
									trees[nx][ny].push_front(1); // 새로 추가되는 나무를 앞쪽에 넣으면 정렬할 필요 X
								}
							}
						}
					}
				}
				// 겨울
				// 양분 추가
				nutri[i][j] += a[i][j];
			}
		}
	}

	int tree_cnt = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (trees[i][j].size() > 0) {
				tree_cnt += trees[i][j].size();
			}
		}
	}

	printf("%d\n", tree_cnt);
	return 0;
}