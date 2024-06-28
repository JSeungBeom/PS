#include <bits/stdc++.h>	

using namespace std;

int arr[10005];
int head, tail = 0;

int front();

int size() {
	return tail - head;
}

bool empty() {
	return size() == 0;
}

void push(int e) {
	arr[tail++] = e;
}

void pop() {
	cout << front() << "\n";
	if (empty()) {
		return;
	}
	head++;
}

int front() {
	if (empty()) {
		return -1;
	}
	return arr[head];
}

int back() {
	if (empty()) {
		return -1;
	}
	return arr[tail - 1];
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	while (n--) {
		string s;
		cin >> s;

		if (s == "push") {
			int e;
			cin >> e;
			push(e);
		}
		else if (s == "pop") {
			pop();
		}
		else if (s == "size") {
			cout << size() << "\n";
		}
		else if (s == "empty") {
			if (empty()) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
		else if (s == "front") {
			cout << front() << "\n";
		}
		else {
			cout << back() << "\n";
		}
	}
}