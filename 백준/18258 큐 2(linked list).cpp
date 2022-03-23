/*
정수를 저장하는 큐를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

명령은 총 여섯 가지이다.

push X: 정수 X를 큐에 넣는 연산이다.
pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다.
만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 큐에 들어있는 정수의 개수를 출력한다.
empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.

*/

#include <iostream>

using namespace std;

struct node {
	node* next; // 노드의 링크 필드
	int data; // 노드의 데이터 필드
}; 

class queue {
private:
	node* frontNode; // linkedlist에서 head와 같은 역할을 하는 노드
	node* backNode; // linkedlist에서 tail과 같은 역할을 하는 노드
	int queuesize; // 큐의 사이즈
public:
	queue() {
		frontNode = NULL;
		backNode = NULL;
		queuesize = 0;
	} // 멤버 변수 초기화

	int size() {
		return queuesize;
	} // 큐의 사이즈를 리턴, O(1)의 시간 복잡도

	bool empty() {
		if (queuesize == 0) {
			return true;
		}
		else
			return false;
	} // 큐가 비었다면 true, 아니라면 false 리턴, O(1)의 시간 복잡도

	void push(int data) {
		node* newNode = new node; // 데이터를 삽입할 새로운 노드
		newNode->data = data; // 데이터 삽입
		newNode->next = NULL; // tail에 삽입하기 때문에, next는 NULL
		if (empty()) {
			frontNode = backNode = newNode;
		} // 큐가 비었다면, front와 back 노드 모두 newNode
		else {
			backNode->next = newNode; // backNode의 뒤에 newNode 삽입
			backNode = newNode; // newNode가 새로운 backNode
		} 
		queuesize++; // 삽입했으니, 큐 사이즈 증가
	} // O(1)의 시간 복잡도

	int front() {
		if (empty()) {
			return -1;
		} // 큐가 비었다면 -1 리턴
		return frontNode->data; // 큐의 맨 앞 데이터를 리턴
	} // O(1)의 시간 복잡도

	int back() {
		if (empty()) {
			return -1;
		} // 큐가 비었다면 -1 리턴
		return backNode->data; // 큐의 맨 뒤 데이터를 리턴
	} // O(1)의 시간 복잡도

	void pop() {
		if (empty()) {
			cout << -1 << "\n";
			return;
		} // 큐가 비었다면 -1 리턴
		cout << front() << "\n"; // 삭제할 노드의 데이터 출력
		if (queuesize == 1) {
			frontNode = backNode = NULL;
		} // 큐 사이즈가 1이라면, front와 back 노드 모두 NULL
		else {
			node* curNode = frontNode; // 삭제할 노드를 메모리 해제하기 위한 변수
			frontNode = frontNode->next; // 데이터를 앞에서 삭제하므로, frontNode는 frontNode의 next
			delete curNode; // 삭제한 노드의 메모리 해제
		}
		queuesize--; // 노드를 삭제하였으니, 큐 사이즈 감소
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
	링크드리스트를 이용한 큐의 구현에서, 모든 기능은 O(1), 즉 상수 시간에 구현이 가능하다.
	이 때, frontNode(head)를 데이터가 나가는 곳, backNode(tail)을 데이터가 들어오는 곳으로
	구현하는 이유는 backNode에서 노드를 삭제할 경우, backNode의 이전 노드를 구하는 과정이
	오래 걸리므로, 이와 같이 구현하는 것이 이상적이다.
*/