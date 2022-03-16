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

struct node {
	int data;
	node* next;
	node* prev;
};

class linkedlist {
private:
	node* head;
	node* tail;
	int stacksize;

public:
	linkedlist() {
		head = NULL;
		tail = NULL;
		stacksize = 0;
	} // constructor, ��� ���� �ʱ�ȭ

	void empty() {
		if (stacksize == 0) {
			cout << 1 << endl;
		}
		else
			cout << 0 << endl;
	}
	void push(int data) {
		node* newNode = new node;
		newNode->data = data;
		newNode->next = NULL;
		if (stacksize == 0) {
			newNode->prev = NULL;
			head = tail = newNode;
		}
		else {
			tail->next = newNode;
			newNode->prev = tail;

			tail = newNode;
		}
		stacksize++;
	} // ������ �� ���� �����͸� �����ϴ� �Լ�, linkedlist�� tail�� �����͸� �����ϴ� append�� �ſ� ����� �����̴�

	void pop() {
		if (stacksize == 0) {
			cout << -1 << endl;
			return;
		}
		node* garbage = tail;
		cout << garbage->data << endl;
		tail = tail->prev; // �����͸� �����ϹǷ�, tail�� tail�� ���� ���� �ȴ� 

		delete garbage; // �����͸� �����Ͽ����Ƿ�, ������ ���� �Ǿ���� �ּҸ� ����
		stacksize--;
	} 

	void size() {
		cout << stacksize << endl;
	}

	void top() {
		if (stacksize == 0) {
			cout << -1 << endl;
			return;
		}
		cout << tail->data << endl;
	} // ������ �� ��(tail)�� �����͸� ���
};

int main() {
	int n;
	linkedlist l;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == "push") {
			int x;
			cin >> x;
			l.push(x);
		}
		else if (s == "pop") {
			l.pop();
		}
		else if (s == "empty") {
			l.empty();
		}
		else if (s == "top") {
			l.top();
		}
		else if (s == "size") {
			l.size();
		}
		else
			break;
	}
} // linkedlist�� ������ stack ����