#include <bits/stdc++.h>

using namespace std;

int n;

class arr_stack {
private:
	int sz;
	int* arr;

public:

	arr_stack(int size) {
		sz = 0;
		arr = new int[size];
	}

	int size() {
		return sz;
	}

	bool empty() {
		return sz == 0;
	}

	void push(int val) {
		arr[sz++] = val;
	}

	int pop() {
		return arr[--sz];
	}

	int top() {
		return arr[sz - 1];
	}
};

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);


	cin >> n;

	arr_stack s(n);

	int command, elem;
	for (int i = 0; i < n; i++) {
		cin >> command;

		switch(command) {
		case 1:
			cin >> elem;
			s.push(elem);
			break;

		case 2:
			if (!s.empty())
				cout << s.pop() << '\n';
			else
				cout << -1 << '\n';
			break;

		case 3:
			cout << s.size() << '\n';
			break;

		case 4:
			if (s.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
			break;

		case 5:
			if (!s.empty())
				cout << s.top() << '\n';
			else
				cout << -1 << '\n';
			break;
		}
	}

}