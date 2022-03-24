/*
N장의 카드가 있다. 각각의 카드는 차례로 1부터 N까지의 번호가 붙어 있으며,
1번 카드가 제일 위에, N번 카드가 제일 아래인 상태로 순서대로 카드가 놓여 있다.

이제 다음과 같은 동작을 카드가 한 장 남을 때까지 반복하게 된다.
우선, 제일 위에 있는 카드를 바닥에 버린다. 
그 다음, 제일 위에 있는 카드를 제일 아래에 있는 카드 밑으로 옮긴다.

예를 들어 N=4인 경우를 생각해 보자. 카드는 제일 위에서부터 1234 의 순서로 놓여있다.
1을 버리면 234가 남는다. 여기서 2를 제일 아래로 옮기면 342가 된다. 
3을 버리면 42가 되고, 4를 밑으로 옮기면 24가 된다.
마지막으로 2를 버리고 나면, 남는 카드는 4가 된다.

N이 주어졌을 때, 제일 마지막에 남게 되는 카드를 구하는 프로그램을 작성하시오.
*/

#include <iostream>

using namespace std;

class queue {
private:
	int* arr; // 큐를 담을 배열
	int arrsize; // 큐의 사이즈
	int capacity; // 배열의 최대 수용량
	int frontidx; // 큐의 맨 앞 데이터의 인덱스
	int rearidx; // 큐의 맨 뒤 데이터의 인덱스

public:
	queue(int capacity) {
		this->capacity = capacity;
		arrsize = 0;
		arr = new int[capacity];
		frontidx = 0; 
		rearidx = 0; // rearidx는 실제로는 맨 뒤 데이터의 다음 인덱스를 가리키므로 0으로 초기화
	} // 멤버 변수 초기화

	int size() {
		return arrsize;
	} // 배열의 사이즈 리턴

	bool empty() {
		if (size() == 0) {
			return true;
		}
		else
			return false;
	} // 큐가 비었을 경우 true, 아니라면 false 리턴

	void enqueue(int data) {
		if (size() == capacity - 1) {
			return;
		} 
		arr[rearidx] = data; // 큐의 맨 뒤 데이터 뒤에 데이터 삽입
		rearidx = (rearidx + 1) % capacity; // 환형 배열 형태로 구현
		// rearidx가 capacity를 벗어나게 될 때에, 다시 인덱스 0부터 삽입
		arrsize++; // 배열의 사이즈 증가
	} // 큐의 rearidx에 데이터를 삽입

	void dequeue() {
		if (empty()) {
			return;
		}
		frontidx = (frontidx + 1) % capacity; // 환형 배열 형태로 구현
		arrsize--; // 배열의 사이즈 감소
	} // 큐의 frontidx에서 데이터 삭제

	int front() {
		if (empty()) {
			return -1;
		}
		return arr[frontidx]; // 맨 앞(frontidx)의 데이터 리턴
	}
}; 
/*
	Queue는 맨 앞에서 데이터를 삭제하고, 맨 뒤에서 데이터를 삽입하는 마치 줄과 같은 자료 구조이다.
	이를 환형 배열로 구현하였을 때에는, 0(N) (N은 배열의 최대 크기)의 공간 복잡도와, 
	각 기능은 O(1)에 수행되는 시간 복잡도를 갖는다. 이를 환형 배열로 구현하는 이유는, 배열은
	인덱스가 최대 크기를 넘어설 경우, 오버플로우가 발생하는데 이를 해결하기 위해 다시 0부터 삽입하는
	환형 배열 형태를 이용한다.
*/

int main() {
	int n;
	
	cin >> n;
	queue q(n + 1);
	// rearidx가 실질적으로 인덱스 n까지 있을 수 있으므로, 크기를 n + 1로 초기화

	for (int i = 1; i <= n; i++) {
		q.enqueue(i);
	} // 큐에 1부터 n까지 데이터 삽입

	while (q.size() != 1) {
		q.dequeue(); // 큐의 맨 앞 데이터 삭제
		q.enqueue(q.front()); // 새로운 맨 앞 데이터를 큐의 뒤에 삽입
		q.dequeue(); // 큐의 맨 앞 데이터 삭제, 위 과정 포함 두 과정이 앞과 뒤의 데이터를 바꾸는 기능
	} // 큐의 사이즈가 1이 될 때까지 반복

	cout << q.front(); // 큐의 맨 앞 데이터 출력
}