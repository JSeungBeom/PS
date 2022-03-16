/*
정수를 저장하는 스택을 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

명령은 총 다섯 가지이다.

push X: 정수 X를 스택에 넣는 연산이다.
pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 
만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 스택에 들어있는 정수의 개수를 출력한다.
empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
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
	} // constructor, 멤버 변수 초기화

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
	} // 스택의 맨 위에 데이터를 삽입하는 함수, linkedlist의 tail에 데이터를 삽입하는 append와 매우 흡사한 형태이다

	void pop() {
		if (stacksize == 0) {
			cout << -1 << endl;
			return;
		}
		node* garbage = tail;
		cout << garbage->data << endl;
		tail = tail->prev; // 데이터를 삭제하므로, tail은 tail의 이전 값이 된다 

		delete garbage; // 데이터를 삭제하였으므로, 쓰레기 값이 되어버린 주소를 삭제
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
	} // 스택의 맨 위(tail)의 데이터를 출력
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
} // linkedlist의 간단한 stack 구현