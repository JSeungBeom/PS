#include <bits/stdc++.h>
using namespace std;

int dist[200002];


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	fill(dist, dist + 200000, -1);

	deque <int> Q;
	Q.push_back(n);
	dist[n] = 0;

	// 범위 내의 모든 거리를 계산
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop_front();
		// 순간이동 하는 인덱스의 거리를 동일하게 맞춘다
		if (cur * 2 < 200000 && dist[cur * 2] == -1) {
			dist[cur * 2] = dist[cur];
			Q.push_front(cur * 2);
		}

		// 그냥 이동하는 경우
		for (int v : {cur + 1, cur - 1}) {
			if (v < 0 || v >= 200000 || dist[v] != -1) continue;

			dist[v] = dist[cur] + 1;
			Q.push_back(v);
		}
	}
	cout << dist[k];
}