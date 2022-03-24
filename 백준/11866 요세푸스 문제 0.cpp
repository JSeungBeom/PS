/*
요세푸스 문제는 다음과 같다.

1번부터 N번까지 N명의 사람이 원을 이루면서 앉아있고, 양의 정수 K(≤ N)가 주어진다.
이제 순서대로 K번째 사람을 제거한다. 
한 사람이 제거되면 남은 사람들로 이루어진 원을 따라 이 과정을 계속해 나간다.
이 과정은 N명의 사람이 모두 제거될 때까지 계속된다. 
원에서 사람들이 제거되는 순서를 (N, K)-요세푸스 순열이라고 한다.
예를 들어 (7, 3)-요세푸스 순열은 <3, 6, 2, 7, 5, 1, 4>이다.

N과 K가 주어지면 (N, K)-요세푸스 순열을 구하는 프로그램을 작성하시오.
*/

#include <iostream>

using namespace std;

class queue {
private:
	int* arr;
	int capacity;
	int frontidx;
	int rearidx;
	int arrsize;

public:
	queue(int capacity) {
		this->capacity = capacity;
		arr = new int[capacity];
		frontidx = 0;
		rearidx = 0;
		arrsize = 0;
	} // 멤버 변수 초기화

	int size() {
		return arrsize;
	} // 큐의 사이즈 리턴

	bool empty() {
		if (size() == 0) {
			return true;
		}
		else
			return false;
	} // 큐의 비어있는지 여부 판단

	void enqueue(int data) {
		if (size() == capacity - 1) {
			return;
		} // exception handling
		arr[rearidx] = data; // queue의 뒤에 데이터 삽입
		rearidx = (rearidx + 1) % capacity; // rearidx를 1 증가,rearidx는 capacity를 넘어서면 다시 0
		arrsize++; // 큐 사이즈 증가
	} // 큐의 뒤에 데이터 삽입

	void dequeue() {
		if (empty()) {
			return;
		} // exception handling
		frontidx = (frontidx + 1) % capacity; // frontidx를 1 증가, frontidx는 capacity를 넘어서면 다시 0
		arrsize--; // 큐 사이즈 감소
	} // 큐의 앞 데이터 삭제

	int front() {
		if (empty()) {
			return;
		}
		return arr[frontidx];
	} // frontidx의 데이터 리턴
};

int main() {
	int n, k;
	cin >> n >> k;
	queue q(n + 1);

	for (int i = 1; i <= n; i++) {
		q.enqueue(i);
	} // 1부터 n까지 큐에 삽입

	cout << "<";

	for(int i = 1; !q.empty(); i++) {
		if (q.size() == 1) {
			cout << q.front();
			q.dequeue();
			break;
		} // 큐 사이즈가 1이라면 ,를 출력하지 않고 반복문 탈출
		if (i % k == 0) {
			cout << q.front() << ", ";
			q.dequeue();
			continue;
		} // i가 k로 나눈 나머지가 0이라면, 큐의 앞에서 데이터 삭제


		int temp = q.front(); // 큐의 앞 쪽 데이터 저장
		q.dequeue(); // 큐의 앞 쪽 데이터 삭제
		q.enqueue(temp); // 큐의 앞 데이터를 뒤로 보냄
	} // 삭제해야될 인덱스의 데이터를 남기고, 앞 데이터들을 큐의 뒤로 삽입
	// 최종적으로 삭제할 인덱스에 도달하면 데이터 삭제
	cout << ">";
}