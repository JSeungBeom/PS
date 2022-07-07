#include <iostream>

using namespace std;

struct node {
	int data;
	node* next;
};

class queue {
private:
	int size;
	node* head;
	node* tail;

public:
	queue() {
		head = tail = NULL;
		size = 0;
	}

	bool empty() {
		return size == 0;
	}

	int sizes() {
		return size;
	}

	void push(int x) {
		node* newNode = new node;
		newNode->data = x;
		if (head == NULL) {
			head = tail = newNode;
			tail->next = NULL;
		}
		else {
			newNode->next = NULL;
			tail->next = newNode;
			tail = newNode;
		}
		size++;
	}

	void pop() {
		if (empty()) {
			cout << -1 << "\n";
			return;
		}

		cout << head->data << "\n";
		node* delNode = head;
		head = head->next;

		delete delNode;
		size--;
	}

	void front() {
		if (empty()) {
			cout << -1 << "\n";
			return;
		}

		cout << head->data << "\n";
	}

	void back() {
		if (empty()){
			cout << -1 << "\n";
			return;
		}

		cout << tail->data << "\n";
	}
};

int main() {
	int n;
	cin >> n;

	queue q;
	while (n--) {
		string s;
		cin >> s;

		if (s == "push") {
			int x;
			cin >> x;
			q.push(x);
		}
		if (s == "pop") {
			q.pop();
		}
		if (s == "size") {
			cout << q.sizes() << "\n";
		}
		if (s == "empty") {
			if (q.empty()) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
		if (s == "front") {
			q.front();
		}
		if (s == "back") {
			q.back();
		}
	}
}

