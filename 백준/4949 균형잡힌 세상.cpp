/*
����� ������ �� �����־�� �Ѵ�. ��� ��, ���� ��� �׸��� ���� ��ȣ�� ������ ��ȣó�� ���̴�.

�������� �ӹ��� � ���ڿ��� �־����� ��,
��ȣ���� ������ �� ������ �ִ��� �Ǵ��ϴ� ���α׷��� ¥�� ���̴�.

���ڿ��� ���ԵǴ� ��ȣ�� �Ұ�ȣ("()") �� ���ȣ("[]")�� 2�����̰�,
���ڿ��� ������ �̷�� ������ �Ʒ��� ����.

��� ���� �Ұ�ȣ("(")�� ������ �Ұ�ȣ(")")�͸� ¦�� �̷�� �Ѵ�.
��� ���� ���ȣ("[")�� ������ ���ȣ("]")�͸� ¦�� �̷�� �Ѵ�.
��� ������ ��ȣ���� �ڽŰ� ¦�� �̷� �� �ִ� ���� ��ȣ�� �����Ѵ�.
��� ��ȣ���� ¦�� 1:1 ��Ī�� �����ϴ�. ��, ��ȣ �ϳ��� �� �̻��� ��ȣ�� ¦�������� �ʴ´�.
¦�� �̷�� �� ��ȣ�� ���� ��, �� ���̿� �ִ� ���ڿ��� ������ ������ �Ѵ�.
�����̸� ���� ���ڿ��� �־����� �� �������� ���ڿ����� �ƴ����� �Ǵ��غ���.
*/

#include <iostream>
#include <string.h>
#include <string>

using namespace std;

class stack {
private:
	char* arr; // char Ÿ�� ������ ������ �迭
	int topIndex; // top�� �ִ� �����͸� �����ϰ� �ִ� index
	int capacity; // �迭�� �ִ� ũ��
	bool flag = false; // ��ȣ�� ¦ ���� �Ǵ�

public:
	stack(int capacity) {
		this->capacity = capacity;
		arr = new char[capacity];
		topIndex = -1;
	} // ��� ������ �ʱ�ȭ
	
	int size() {
		return topIndex + 1;
	} // ������ ũ�� ����

	bool empty() {
		if (size() == 0) {
			return true;
		}
		else
			return false;
	} // ������ ������� �Ǵ�

	bool check() {
		if (!empty() || flag == true) {
			return true;
		}
		else
			return false;
	}

	void push(char data) {
		if (capacity == size()) {
			return;
		}
		if (data == '(' || data == '[') {
			arr[++topIndex] = data;
		} // ��ȣ�� ���� ��ȣ�� ��� ���ÿ� �߰�
		else if (data == ')') {
			if (empty()) {
				flag = true;
				return;
			} // ������ ����� ���, ¦�� ���� �ʴ� ����̹Ƿ� flag�� true�� �����ϰ� ����
			if (top() == '(') {
				pop();
			} // ������ �Ұ�ȣ�� �ԷµǾ��ٸ�, ���� �Ұ�ȣ�� stack�� top�� ������ pop ����
			else {
				flag = true;
				return;
			} // ��ȣ�� ����� ���� �ʴ� ��� flag�� true�� �����ϰ� ����
		} 
		else if (data == ']') {
			if (empty()) {
				flag = true;
				return;
			} // ������ �� ���

			if (top() == '[') {
				pop();
			}
			else {
				flag = true;
				return;
			}
		}
	}



	char top() {
		if (empty()) {
			exit(1);
		}
		return arr[topIndex];
	} // stack�� top �����͸� ����

	void pop() {
		if (empty()) {
			return;
		}
		topIndex--;
	} // ������ top �����͸� ����
};

int main() {
	while (true) {
		string s;
		getline(cin, s);
		// getline(cin, string) : ��Ʈ���� ���� �����Ͽ� �Է¹޴� �Լ�

		if (s == ".") {
			return 0;
		}

		stack st(s.length());
		for (int i = 0; i < s.length(); i++) {
			st.push(s[i]);
		}
		if (st.check()) {
			cout << "no" << endl;
		}
		else
			cout << "yes" << endl;

	}
}