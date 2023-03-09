#include <bits/stdc++.h>

using namespace std;

int vertex1, vertex2, weight;
int V, E;
// 가중치, 정점1, 정점2를 담는 배열
tuple<int, int, int> edges[100003];

// Union Find를 진행할 정점 배열
vector<int> parents(10003, 0);

int getParent(int x) {
	if (parents[x] == x) return x;
	return parents[x] = getParent(parents[x]);
}

void unionParent(int u, int v) {
	u = getParent(u);
	v = getParent(v);
	if (u < v) parents[u] = v;
	else parents[v] = u;
}

bool is_different_group(int u, int v) {
	u = getParent(u);
	v = getParent(v);

	if (u == v) return 0;
	return 1;
}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> V >> E;

	int ans = 0;
	int cnt = 0;

	for (int i = 1; i <= V; i++) {
		parents[i] = i;
	}

	for (int i = 0; i < E; i++) {
		cin >> vertex1 >> vertex2 >> weight;
		edges[i] = { weight, vertex1, vertex2 };
	}

	// 간선의 가중치, 정점1, 정점2 순으로 오름차순으로 정렬
	sort(edges, edges + E); // sort 함수의 특성에 따라, O(ElogE) time

	for (int i = 0; i < E; i++) {
		int a, b, cost;
		tie(cost, a, b) = edges[i]; // 가중치, 정점 a, 정점 b 꺼내기
		// 정점 a, 정점 b가 다른 그룹이라면(즉, 사이클을 이루지 않는다면)
		if (is_different_group(a, b)) { 
			unionParent(a, b); // 최소 신장 트리에 간선 추가
			ans += cost; // 가중치 더하기
			cnt++; // 간선 개수 세기
		}

		// 간선 개수가 V - 1이라면, 최소 신장 트리가 완성이므로 빠져나가기
		if (cnt == V - 1) break;
	}

	cout << ans;
}