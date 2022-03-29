#include <iostream>

using namespace std;

struct node {
	node* next; // 다음 노드를 가리키는 링크
	node* prev; // 이전 노드를 가리키는 링크
	int data; // 데이터
}; // 노드
class Deque {
private:
	node* frontNode; // 맨 앞의 노드(head)
	node* rearNode; // 맨 뒤의 노드(tail)
	int n; // 덱 사이즈

public:
	Deque() {
		frontNode = rearNode = NULL;
		n = 0;
	} // 생성자, 멤버 변수 초기화

	int size() {
		return n;
	} // 덱 사이즈 리턴

	bool empty() {
		return (n == 0);
	} // 덱이 비었다면 true, 아니라면 false 리턴

	int front() {
		if (empty()) {
			return -1;
		}
		return frontNode->data;
	} // front 위치의 데이터 리턴

	int back() {
		if (empty()) {
			return -1;
		}
		return rearNode->data;
	} // back 위치의 데이터 리턴

	void push_front(int data) {
		node* newNode = new node; // 새로운 노드
		newNode->data = data; // 데이터 삽입
		newNode->prev = NULL;
		if (empty()) {
			newNode->next = NULL;
			frontNode = rearNode = newNode;
		} // 큐가 비었을 때
		else {
			frontNode->prev = newNode;
			newNode->next = frontNode;
			frontNode = newNode;
		} // 기존의 frontNode와 newNode의 링크 연결
		n++; // 덱 사이즈 증가
	} // front 위치에 데이터 삽입

	void push_back(int data) {
		node* newNode = new node; // 새 노드
		newNode->data = data; // 데이터 삽입
		newNode->next = NULL;
		if (empty()) {
			newNode->prev = NULL;
			frontNode = rearNode = newNode;
		} // 큐가 비었을 때
		else {
			rearNode->next = newNode;
			newNode->prev = rearNode;
			rearNode = newNode;
		} // 기존의 rearNode와 newNode의 링크 연결
		n++; // 덱 사이즈 증가
	} // rear 위치에 데이터 삽입

	void pop_front() {
		if (empty()) {
			cout << -1 << "\n";
			return;
		} // 큐가 비었을 때 종료
		cout << front() << "\n";
		node* curNode = frontNode; // 삭제 될 노드
		if (n == 1) {
			frontNode = rearNode = NULL;
		} // 큐 사이즈가 1일 때
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
// doubly linked list를 이용한 deque의 구현, O(n)의 space complexity와 모든 기능이 O(1)의 time complexity를 갖는다
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