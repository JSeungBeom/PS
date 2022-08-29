#include <bits/stdc++.h>

using namespace std;

int n, w, L;
int t;
queue<int> truck;
int bridge[102];

bool isEmpty() {
	for (int i = 0; i < w; i++) {
		if (bridge[i]) return false;
	}

	return true;
}

void go() {
	for (int i = w - 1; i > 0; i--) {
		bridge[i] = bridge[i - 1];
	}

	bridge[0] = 0;
}

int calc() {
	int sum = 0;
	for (int i = 0; i < w; i++) {
		sum += bridge[i];
	}
	return sum;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> w >> L;
	
	for (int i = 0; i < n; i++) {
		int c;
		cin >> c;
		truck.push(c);
	}
	
	do {
		int tmp = calc();
		if (tmp <= L) {
			go();
			tmp = calc();
		}

		if (!truck.empty() && (tmp + truck.front() <= L)) {
			bridge[0] = truck.front(); truck.pop();
		}


		t++;
	} while (!isEmpty());

	cout << t;
	
}