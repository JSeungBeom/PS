/*
N���� ī�尡 �ִ�. ������ ī��� ���ʷ� 1���� N������ ��ȣ�� �پ� ������,
1�� ī�尡 ���� ����, N�� ī�尡 ���� �Ʒ��� ���·� ������� ī�尡 ���� �ִ�.

���� ������ ���� ������ ī�尡 �� �� ���� ������ �ݺ��ϰ� �ȴ�.
�켱, ���� ���� �ִ� ī�带 �ٴڿ� ������. 
�� ����, ���� ���� �ִ� ī�带 ���� �Ʒ��� �ִ� ī�� ������ �ű��.

���� ��� N=4�� ��츦 ������ ����. ī��� ���� ���������� 1234 �� ������ �����ִ�.
1�� ������ 234�� ���´�. ���⼭ 2�� ���� �Ʒ��� �ű�� 342�� �ȴ�.
3�� ������ 42�� �ǰ�, 4�� ������ �ű�� 24�� �ȴ�. 
���������� 2�� ������ ����, ���� ī��� 4�� �ȴ�.

N�� �־����� ��, ���� �������� ���� �Ǵ� ī�带 ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/

#include <iostream>

using namespace std;

struct node {
	node* next;
	int data;
};

class queue {
private:
	node* frontNode;
	node* rearNode;
	int listsize;

public:
	queue() {
		frontNode = NULL;
		rearNode = NULL;
		listsize = 0;
	} // ��� ���� �ʱ�ȭ

	int size() {
		return listsize;
	}

	bool empty() {
		if (size() == 0) {
			return true;
		}
		else
			return false;
	}

	void enqueue(int data) {
		node* newNode = new node;
		newNode->data = data;
		newNode->next = NULL;
		if (empty()) {
			frontNode = rearNode = newNode;
		}
		else {
			rearNode->next = newNode;
			rearNode = newNode;
		}
		listsize++;
	}

	void dequeue() {
		if (empty()) {
			return;
		}
		else {
			node* curNode = frontNode;
			frontNode = frontNode->next;
			delete curNode;
		}
		listsize--;
	}

	int front() {
		if (empty()) {
			return -1;
		}
		return frontNode->data;
	}
};

int main() {
	int n;
	cin >> n;
	queue q;
	for (int i = 1; i <= n; i++) {
		q.enqueue(i);
	}

	while (q.size() != 1) {
		q.dequeue();
		q.enqueue(q.front());
		q.dequeue();
	}

	cout << q.front();
}