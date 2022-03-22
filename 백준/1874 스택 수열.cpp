/*
���� (stack)�� �⺻���� �ڷᱸ�� �� �ϳ���, ��ǻ�� ���α׷��� �ۼ��� �� ���� �̿�Ǵ� �����̴�.
������ �ڷḦ �ִ� (push) �Ա��� �ڷḦ �̴� (pop) �Ա��� ����
���� ���߿� �� �ڷᰡ ���� ���� ������ (LIFO, Last in First out) Ư���� ������ �ִ�.

1���� n������ ���� ���ÿ� �־��ٰ� �̾� �þ�������ν�, �ϳ��� ������ ���� �� �ִ�.
�̶�, ���ÿ� push�ϴ� ������ �ݵ�� ���������� ��Ű���� �Ѵٰ� ����.
������ ������ �־����� �� ������ �̿��� �� ������ ���� �� �ִ��� ������, 
�ִٸ� � ������ push�� pop ������ �����ؾ� �ϴ����� �˾Ƴ� �� �ִ�.
�̸� ����ϴ� ���α׷��� �ۼ��϶�.
*/

#include <iostream>

using namespace std;

class stack {
private:
	int* arr;
	int capacity;
	int topIndex;
	char* ar; 

public:
	stack(int capacity) {
		this->capacity = capacity;
		arr = new int[capacity];
		ar = new char[capacity];
		topIndex = -1;
	}  // ������� �ʱ�ȭ

	int size() {
		return topIndex + 1;
	} // ������ ������(topIndex+1)�� ����

	bool empty() {
		if (size() == 0) {
			return true;
		}
		else
			return false;
	} // ������ ����ٸ� true, �ƴ϶�� false�� ����

	void push(int data) {
		if (size() == capacity) {
			return;
		} // ������ �迭�� ũ�⸦ �Ѿ�� ��� exception

		arr[++topIndex] = data; // topIndex�� 1 ������Ű��, �ش� �ε����� �����͸� ����
	}

	void pop() {
		if (empty()) {
			return;
		} // ������ ����ִ� ��� ����
		topIndex--;  // ������ topIndex�� 1 ����
	}

	int top() {
		if (empty()) {
			return -1;
		} // ������ ����ִ� ��� ����
		return arr[topIndex];
	} // ������ top �����͸� ����

}; // �迭�� �̿��� stack�� ��� ��� ������ �־, �������⵵�� O(N)(N�� �迭�� ũ��)
// �ð����⵵�� O(1)�̴�

int main() {
	int n;
	cin >> n;

	stack st(n); // ��ü ����
	char check[1000000];// ��ȣ�� ������ �迭
	int num = 1; // ���� �ȿ� ������ int Ÿ�� ������
	int checknum = -1; // ��ȣ ���� �迭�� index��

	for (int i = 0; i < n; i++) {
		int data;
		cin >> data;

		if (num <= data) {
			for (num; num <= data; num++) {
				st.push(num);
				check[++checknum] = '+';
			} // num�� data ���� �� ������ stack�� push
			st.pop(); // num�� data���� �Ǿ��ٸ�, stack���� pop
			check[++checknum] = '-';
		}
		else {
			if (st.top() < data) {
				check[++checknum] = 'N';
				break;
			} // ������ top �����ͺ���, �Էµ� �����Ͱ� ū ��� 
				st.pop(); // �Է¹��� �����ͺ��� num�� ũ�ٸ�, pop
				check[++checknum] = '-';
		}
	}

	for (int i = 0; i < checknum + 1; i++) {
		if (check[i] == 'N') {
			cout << "NO";
			return 0;
		}
	} // ��ȣ �迭�� N�� �ִٸ�, ������ �� �� �����Ƿ� NO�� ����ϰ� ����

	for (int i = 0; i < checknum + 1; i++) {
		cout << check[i] << "\n";
	} // ��ȣ �迭�� ��ҵ��� ���
}