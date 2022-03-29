#include <iostream>

using namespace std;

struct node {
	node* next; // ���� ��带 ����Ű�� ��ũ
	node* prev; // ���� ��带 ����Ű�� ��ũ
	int data; // ������
}; // ���
class Deque {
private:
	node* frontNode; // �� ���� ���(head)
	node* rearNode; // �� ���� ���(tail)
	int n; // �� ������

public:
	Deque() {
		frontNode = rearNode = NULL;
		n = 0;
	} // ������, ��� ���� �ʱ�ȭ

	int size() {
		return n;
	} // �� ������ ����

	bool empty() {
		return (n == 0);
	} // ���� ����ٸ� true, �ƴ϶�� false ����

	int front() {
		if (empty()) {
			return -1;
		}
		return frontNode->data;
	} // front ��ġ�� ������ ����

	int back() {
		if (empty()) {
			return -1;
		}
		return rearNode->data;
	} // back ��ġ�� ������ ����

	void push_front(int data) {
		node* newNode = new node; // ���ο� ���
		newNode->data = data; // ������ ����
		newNode->prev = NULL;
		if (empty()) {
			newNode->next = NULL;
			frontNode = rearNode = newNode;
		} // ť�� ����� ��
		else {
			frontNode->prev = newNode;
			newNode->next = frontNode;
			frontNode = newNode;
		} // ������ frontNode�� newNode�� ��ũ ����
		n++; // �� ������ ����
	} // front ��ġ�� ������ ����

	void push_back(int data) {
		node* newNode = new node; // �� ���
		newNode->data = data; // ������ ����
		newNode->next = NULL;
		if (empty()) {
			newNode->prev = NULL;
			frontNode = rearNode = newNode;
		} // ť�� ����� ��
		else {
			rearNode->next = newNode;
			newNode->prev = rearNode;
			rearNode = newNode;
		} // ������ rearNode�� newNode�� ��ũ ����
		n++; // �� ������ ����
	} // rear ��ġ�� ������ ����

	void pop_front() {
		if (empty()) {
			cout << -1 << "\n";
			return;
		} // ť�� ����� �� ����
		cout << front() << "\n";
		node* curNode = frontNode; // ���� �� ���
		if (n == 1) {
			frontNode = rearNode = NULL;
		} // ť ����� 1�� ��
		else {
			frontNode = frontNode->next;
			frontNode->prev = NULL;
		}
		delete curNode;
		n--;
	}

	void pop_back() {
		if (empty()) {
			cout << -1 << "\n";
			return;
		}
		cout << back() << "\n";
		node* curNode = rearNode;
		if (n == 1) {
			frontNode = rearNode = NULL;
		}
		else {
			rearNode = rearNode->prev;
			rearNode->next = NULL;
		}
		delete curNode;
		n--;
	}
};
// doubly linked list�� �̿��� deque�� ����, O(n)�� space complexity�� ��� ����� O(1)�� time complexity�� ���´�
int main() {
	int n;
	Deque d;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string command;
		int data;
		cin >> command;
		if (command == "push_back") {
			cin >> data;
			d.push_back(data);
		}
		else if (command == "push_front") {
			cin >> data;
			d.push_front(data);
		}
		else if (command == "pop_front") {
			d.pop_front();
		}
		else if (command == "pop_back") {
			d.pop_back();
		}
		else if (command == "size") {
			cout << d.size() << "\n";
		}
		else if (command == "empty") {
			if (d.empty()) {
				cout << 1 << "\n";
			}
			else
				cout << 0 << "\n";
		}
		else if (command == "front") {
			cout << d.front() << "\n";
		}
		else if (command == "back") {
			cout << d.back() << "\n";
		}
		else
			break;
	}
}