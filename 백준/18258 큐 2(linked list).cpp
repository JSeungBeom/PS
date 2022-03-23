/*
������ �����ϴ� ť�� ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.

����� �� ���� �����̴�.

push X: ���� X�� ť�� �ִ� �����̴�.
pop: ť���� ���� �տ� �ִ� ������ ����, �� ���� ����Ѵ�.
���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ť�� ����ִ� ������ ������ ����Ѵ�.
empty: ť�� ��������� 1, �ƴϸ� 0�� ����Ѵ�.
front: ť�� ���� �տ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
back: ť�� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.

*/

#include <iostream>

using namespace std;

struct node {
	node* next; // ����� ��ũ �ʵ�
	int data; // ����� ������ �ʵ�
}; 

class queue {
private:
	node* frontNode; // linkedlist���� head�� ���� ������ �ϴ� ���
	node* backNode; // linkedlist���� tail�� ���� ������ �ϴ� ���
	int queuesize; // ť�� ������
public:
	queue() {
		frontNode = NULL;
		backNode = NULL;
		queuesize = 0;
	} // ��� ���� �ʱ�ȭ

	int size() {
		return queuesize;
	} // ť�� ����� ����, O(1)�� �ð� ���⵵

	bool empty() {
		if (queuesize == 0) {
			return true;
		}
		else
			return false;
	} // ť�� ����ٸ� true, �ƴ϶�� false ����, O(1)�� �ð� ���⵵

	void push(int data) {
		node* newNode = new node; // �����͸� ������ ���ο� ���
		newNode->data = data; // ������ ����
		newNode->next = NULL; // tail�� �����ϱ� ������, next�� NULL
		if (empty()) {
			frontNode = backNode = newNode;
		} // ť�� ����ٸ�, front�� back ��� ��� newNode
		else {
			backNode->next = newNode; // backNode�� �ڿ� newNode ����
			backNode = newNode; // newNode�� ���ο� backNode
		} 
		queuesize++; // ����������, ť ������ ����
	} // O(1)�� �ð� ���⵵

	int front() {
		if (empty()) {
			return -1;
		} // ť�� ����ٸ� -1 ����
		return frontNode->data; // ť�� �� �� �����͸� ����
	} // O(1)�� �ð� ���⵵

	int back() {
		if (empty()) {
			return -1;
		} // ť�� ����ٸ� -1 ����
		return backNode->data; // ť�� �� �� �����͸� ����
	} // O(1)�� �ð� ���⵵

	void pop() {
		if (empty()) {
			cout << -1 << "\n";
			return;
		} // ť�� ����ٸ� -1 ����
		cout << front() << "\n"; // ������ ����� ������ ���
		if (queuesize == 1) {
			frontNode = backNode = NULL;
		} // ť ����� 1�̶��, front�� back ��� ��� NULL
		else {
			node* curNode = frontNode; // ������ ��带 �޸� �����ϱ� ���� ����
			frontNode = frontNode->next; // �����͸� �տ��� �����ϹǷ�, frontNode�� frontNode�� next
			delete curNode; // ������ ����� �޸� ����
		}
		queuesize--; // ��带 �����Ͽ�����, ť ������ ����
	}
};

int main() {
	int n;

	cin >> n;
	queue q;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == "push") {
			int data;
			cin >> data;
			q.push(data);
		}
		else if (s == "front") {
			cout << q.front() << "\n";
		}
		else if (s == "back") {
			cout << q.back() << "\n";
		}
		else if (s == "size") {
			cout << q.size() << "\n";
		}
		else if (s == "empty") {
			if (q.empty()) {
				cout << 1 << "\n";
			}
			else
				cout << 0 << "\n";
		}
		else if (s == "pop") {
			q.pop();
		}
		else
			break;
	}
}

/*
	��ũ�帮��Ʈ�� �̿��� ť�� ��������, ��� ����� O(1), �� ��� �ð��� ������ �����ϴ�.
	�� ��, frontNode(head)�� �����Ͱ� ������ ��, backNode(tail)�� �����Ͱ� ������ ������
	�����ϴ� ������ backNode���� ��带 ������ ���, backNode�� ���� ��带 ���ϴ� ������
	���� �ɸ��Ƿ�, �̿� ���� �����ϴ� ���� �̻����̴�.
*/