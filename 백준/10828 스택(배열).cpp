/*
������ �����ϴ� ������ ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.
����� �� �ټ� �����̴�.

push X: ���� X�� ���ÿ� �ִ� �����̴�.
pop: ���ÿ��� ���� ���� �ִ� ������ ����, �� ���� ����Ѵ�.
���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ���ÿ� ����ִ� ������ ������ ����Ѵ�.
empty: ������ ��������� 1, �ƴϸ� 0�� ����Ѵ�.
top: ������ ���� ���� �ִ� ������ ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
*/

#include <iostream>

using namespace std;

class stack {
private:
	int stck[10000];
	int	stacksize; // ������ size�� ����� ����

public:
	stack() {
		stacksize = 0;
		for (int i = 0; i < 10000; i++) {
			stck[i] = 0;
		}
	} // ������� �ʱ�ȭ constructor

	void empty() {
		if (stacksize == 0) {
			cout << 1 << endl;
		}
		else {
			cout << 0 << endl;
		}
	} 
	void push(int x) {
		stck[stacksize] = x;
		stacksize++; 
 	} // ������ �� ��(stacksize)�� �����͸� �߰��ϰ�, ����� ����

	void pop() {
		if (stacksize == 0) {
			cout << -1 << endl;
			return;
		}
		cout << stck[stacksize - 1] << endl;
		stck[stacksize - 1] = 0;
		stacksize--;
	} // ������ �� �� �����͸� 0���� ����(����)�ϰ�, ����� ����

	void top() {
		if (stacksize == 0) {
			cout << -1 << endl;
			return;
		}
		else {
			cout << stck[stacksize - 1] << endl;
		} 
 	} // ������ �� �� �����͸� ���

	void size() {
		cout << stacksize << endl;
	} // ������ ������ ���
};

int main() {
	int n;
	stack st;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		int x;
		if (s == "push") {
			cin >> x;
			st.push(x);
		}
		else if (s == "top") {
			st.top();
		}
		else if (s == "size") {
			st.size();
		}
		else if (s == "empty") {
			st.empty();
		}
		else if (s == "pop") {
			st.pop();
		}
		else
			break;
	}
}

// �迭�� �̿��� ������ stack ����