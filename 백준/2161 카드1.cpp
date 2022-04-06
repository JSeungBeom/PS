/*
N���� ī�尡 �ִ�. ������ ī��� ���ʷ� 1���� N������ ��ȣ�� �پ� ������, 1�� ī�尡 ���� ����,
N�� ī�尡 ���� �Ʒ��� ���·� ������� ī�尡 ���� �ִ�.

���� ������ ���� ������ ī�尡 �� �� ���� ������ �ݺ��ϰ� �ȴ�.
�켱, ���� ���� �ִ� ī�带 �ٴڿ� ������. 
�� ����, ���� ���� �ִ� ī�带 ���� �Ʒ��� �ִ� ī�� ������ �ű��.

���� ��� N=4�� ��츦 ������ ����. ī��� ���� ���������� 1234 �� ������ �����ִ�. 
1�� ������ 234�� ���´�. ���⼭ 2�� ���� �Ʒ��� �ű�� 342�� �ȴ�.
3�� ������ 42�� �ǰ�, 4�� ������ �ű�� 24�� �ȴ�.
���������� 2�� ������ ����, ���� ī����� ������� 1 3 2�� �ǰ�, ���� ī��� 4�� �ȴ�.

N�� �־����� ��, ���� ī����� ������� ����ϰ�,
�������� ���� �Ǵ� ī�带 ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/

#include <iostream>

using namespace std;

class Queue {
private:
	int* arr;
	int capacity;
	int n;
	int frontidx;
	int rearidx; // rearidx�� �����͸� �����Ϸ��� ��, �� ���� �� �� �ε��� + 1�̴�

public:
	// ������, ��� ���� �ʱ�ȭ
	Queue(int capacity) {
		this->capacity = capacity;
		arr = new int[capacity];
		frontidx = rearidx = 0;
	}

	// ť�� ����� ����
	int size() {
		return n;
	}

	// ť�� ������� Ȯ��
	bool empty() {
		return (n == 0);
	}

	// ť�� rearidx�� data �߰�
	void push_back(int data) {
		if (size() == capacity) {
			return;
		}
		arr[rearidx] = data;
		rearidx = (rearidx + 1) % capacity;
		n++;
	}

	// ť�� frontidx�� data ����
	void pop_front() {
		if (empty()) {
			return;
		}
		frontidx = (frontidx + 1) % capacity;
		n--;
	}

	// ť�� frontidx�� ������ ����
	int front() {
		return arr[frontidx];
	}
};

int main() {
	int n;
	cin >> n;
	Queue q(n);
	// ť�� 1 ~ n�� �����͸� ����
	for (int i = 1; i <= n; i++) {
		q.push_back(i);
	}

	while (true) {
		cout << q.front() << " ";
		q.pop_front(); // frontidx�� ������ ����
		if (q.empty()) {
			break;
		} // ť�� ����ٸ� while�� Ż��
		int temp = q.front(); // ť�� frontidx�� �����͸� �ӽ� ����
		q.pop_front(); // frontidx�� ������ ����
		q.push_back(temp); // �ӽ������� �����͸� �ٽ� rearidx�� ����
	}
}