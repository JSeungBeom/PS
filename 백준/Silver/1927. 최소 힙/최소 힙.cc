#include <bits/stdc++.h>
using namespace std;

int heap[100005];
int sz = 0; // heap에 들어있는 원소의 수
int n;

void push(int x) {
	heap[++sz] = x;

	int idx = sz;

	while (idx != 1) {
		int par = idx / 2;

		if (heap[par] > heap[idx]) {
			swap(heap[par], heap[idx]);
			idx /= 2;
		}
		else {
			return;
		}
	}
}

int top() {
	if (sz == 0) {
		return 0;
	}

	return heap[1];
}

void pop() {
	if (sz == 0)
		return;

	heap[1] = heap[sz--];

	int idx = 1;
	
	while (idx * 2 <= sz) {
		int lc = idx * 2;
		int rc = idx * 2 + 1;
		int min_c = lc;

		if (rc <= sz && heap[rc] < heap[lc])
			min_c = rc;
		if (heap[idx] <= heap[min_c]) break;
		swap(heap[idx], heap[min_c]);
		idx = min_c;
	}
}

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n;

	int x;

	while (n--) {
		cin >> x;

		if (x == 0) {
			cout << top() << '\n';
			pop();
		}
		else {
			push(x);
		}
	}
}