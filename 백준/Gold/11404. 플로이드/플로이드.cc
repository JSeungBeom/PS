#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9; // 아무리 커도 간선 * 비용 이하
int n, m;
tuple<int, int, int> bus[100003];
int dist[103][103];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		bus[i] = { a, b, c };
	}

	// 가중치 무한으로 초기화
	for (int i = 1; i <= n; i++) {
		fill(dist[i] + 1, dist[i] + n + 1, INF);
	}

	// 루프에 대한 처리 (시작 도시 != 도착 도시)
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) dist[i][j] = 0;
		}
	}

	for (int i = 0; i < m; i++) {
		int st, en, cost;
		tie(st, en, cost) = bus[i];
		dist[st][en] = min(dist[st][en], cost); // 노선이 2개 이상일수도 있음
	}

	// O(V^3) time
	for (int mid = 1; mid <= n; mid++) {
		for (int st = 1; st <= n; st++) {
			for (int en = 1; en <= n; en++) {
				dist[st][en] = min(dist[st][en], dist[st][mid] + dist[mid][en]);
			}
		}
	}

	for (int st = 1; st <= n; st++) {
		for (int en = 1; en <= n; en++) {
			if (dist[st][en] == INF) cout << 0 << " "; // 경로가 없으면 0 
			else cout << dist[st][en] << " "; // 최소 비용 출력
		}
		cout << "\n";
	}


	
}