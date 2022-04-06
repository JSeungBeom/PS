/*
N장의 카드가 있다. 각각의 카드는 차례로 1부터 N까지의 번호가 붙어 있으며, 1번 카드가 제일 위에,
N번 카드가 제일 아래인 상태로 순서대로 카드가 놓여 있다.

이제 다음과 같은 동작을 카드가 한 장 남을 때까지 반복하게 된다.
우선, 제일 위에 있는 카드를 바닥에 버린다. 
그 다음, 제일 위에 있는 카드를 제일 아래에 있는 카드 밑으로 옮긴다.

예를 들어 N=4인 경우를 생각해 보자. 카드는 제일 위에서부터 1234 의 순서로 놓여있다. 
1을 버리면 234가 남는다. 여기서 2를 제일 아래로 옮기면 342가 된다.
3을 버리면 42가 되고, 4를 밑으로 옮기면 24가 된다.
마지막으로 2를 버리고 나면, 버린 카드들은 순서대로 1 3 2가 되고, 남는 카드는 4가 된다.

N이 주어졌을 때, 버린 카드들을 순서대로 출력하고,
마지막에 남게 되는 카드를 출력하는 프로그램을 작성하시오.
*/

#include <iostream>

using namespace std;

class Queue {
private:
	int* arr;
	int capacity;
	int n;
	int frontidx;
	int rearidx; // rearidx는 데이터를 삽입하려는 곳, 즉 실제 맨 뒤 인덱스 + 1이다

public:
	// 생성자, 멤버 변수 초기화
	Queue(int capacity) {
		this->capacity = capacity;
		arr = new int[capacity];
		frontidx = rearidx = 0;
	}

	// 큐의 사이즈를 리턴
	int size() {
		return n;
	}

	// 큐가 비었는지 확인
	bool empty() {
		return (n == 0);
	}

	// 큐의 rearidx에 data 추가
	void push_back(int data) {
		if (size() == capacity) {
			return;
		}
		arr[rearidx] = data;
		rearidx = (rearidx + 1) % capacity;
		n++;
	}

	// 큐의 frontidx에 data 삭제
	void pop_front() {
		if (empty()) {
			return;
		}
		frontidx = (frontidx + 1) % capacity;
		n--;
	}

	// 큐의 frontidx의 데이터 리턴
	int front() {
		return arr[frontidx];
	}
};

int main() {
	int n;
	cin >> n;
	Queue q(n);
	// 큐에 1 ~ n의 데이터를 삽입
	for (int i = 1; i <= n; i++) {
		q.push_back(i);
	}

	while (true) {
		cout << q.front() << " ";
		q.pop_front(); // frontidx의 데이터 삭제
		if (q.empty()) {
			break;
		} // 큐가 비었다면 while문 탈출
		int temp = q.front(); // 큐의 frontidx의 데이터를 임시 저장
		q.pop_front(); // frontidx의 데이터 삭제
		q.push_back(temp); // 임시저장한 데이터를 다시 rearidx에 삽입
	}
}