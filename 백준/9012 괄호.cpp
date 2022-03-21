/*
��ȣ ���ڿ�(Parenthesis String, PS)�� �� ���� ��ȣ ��ȣ�� ��(�� �� ��)�� ������ �����Ǿ� �ִ� ���ڿ��̴�.
�� �߿��� ��ȣ�� ����� �ٸ��� ������ ���ڿ��� �ùٸ� ��ȣ ���ڿ�(Valid PS, VPS)�̶�� �θ���.
�� ���� ��ȣ ��ȣ�� �� ��( )�� ���ڿ��� �⺻ VPS �̶�� �θ���.
���� x �� VPS ��� �̰��� �ϳ��� ��ȣ�� ���� ���ο� ���ڿ� ��(x)���� VPS �� �ȴ�.
�׸��� �� VPS x �� y�� ����(concatenation)��Ų ���ο� ���ڿ� xy�� VPS �� �ȴ�.
���� ��� ��(())()���� ��((()))�� �� VPS ������ ��(()(��,
��(())()))�� , �׸��� ��(()�� �� ��� VPS �� �ƴ� ���ڿ��̴�.

�������� �Է����� �־��� ��ȣ ���ڿ��� VPS ���� �ƴ����� �Ǵ��ؼ�
�� ����� YES �� NO �� ��Ÿ����� �Ѵ�.
*/

#include <iostream>

using namespace std;

class stack {
private:
	int topIndex;
	char* arr;
	int capacity;
	bool flag; // ���ڿ��� VPS���� �Ǵ��ϴ� ����

public:
	stack(int capacity) {
		this->capacity = capacity;
		arr = new char[capacity];
		topIndex = -1;
		flag = false;
	} // ������ ��� ���� �ʱ�ȭ

	int size() {
		return topIndex + 1;
	} // ������ ����� ����

	bool empty() {
		if (size() == 0) {
			return true;
		}
		else
			return false;
	} // ������ ������� �Ǵ�

	bool vps() {
		if (flag == true || !empty()) {
			return true;
		}
		else
			return false;
	}


	void push(char data) {
		if (size() == capacity) {
			return;
		} // ������ ����� �迭�� ũ��� ���� ���

		if (data == '(') {
			arr[++topIndex] = data;
		} // topIndex�� 1 ������Ű��, �ش� �ε����� �����͸� ����
		// ���� ��ȣ�� ���� �ݴ� ��ȣ�� ���� VPS�� �����ǹǷ�, �ϴ� ���ÿ� push�Ѵ�
		else if (data == ')') {
			if (empty()) {
				flag = true;
				return;
			}
			pop();
		} // �ݴ� ��ȣ�� ����������, ���ÿ� ���� ���� ��ȣ�� pop()�Ѵ�
		// �� ��������, ������ ũ�Ⱑ 0�� ���, VPS�� �ƴϹǷ� false�� ����
	}
	
	char top() {
		if (empty()) {
			exit(1);
		}
		return arr[topIndex];
	}

	void pop() {
		if (empty()) {
			exit(1);
		}
		topIndex--;
	}
};

int main() {
	int t;

	cin >> t;

	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;
		stack st(s.length());
		for (int j = 0; j < s.length(); j++) {
			st.push(s[j]);
		}
		if (st.vps()) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
		}
	}

}

/* 
ex) ((()) �ݴ� ��ȣ�� ������ ��� :
��� ���ڿ��� ���� �˻簡 ��������, ���ÿ� �����Ͱ� �����ִ� ���
ex) ())) ���� ��ȣ�� ������ ��� :
pop()�� �����ϴ� ��������, ���ÿ� �����Ͱ� ���� ���
ex) )( ��ȣ�� ������ ������, ¦�� ���� �ʴ� ��� :
���� ��ȣ�� ������ ���� �����ϴ�
*/