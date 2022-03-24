/*
�似Ǫ�� ������ ������ ����.

1������ N������ N���� ����� ���� �̷�鼭 �ɾ��ְ�, ���� ���� K(�� N)�� �־�����.
���� ������� K��° ����� �����Ѵ�. 
�� ����� ���ŵǸ� ���� ������ �̷���� ���� ���� �� ������ ����� ������.
�� ������ N���� ����� ��� ���ŵ� ������ ��ӵȴ�. 
������ ������� ���ŵǴ� ������ (N, K)-�似Ǫ�� �����̶�� �Ѵ�.
���� ��� (7, 3)-�似Ǫ�� ������ <3, 6, 2, 7, 5, 1, 4>�̴�.

N�� K�� �־����� (N, K)-�似Ǫ�� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
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
	} // ��� ���� �ʱ�ȭ

	int size() {
		return arrsize;
	} // ť�� ������ ����

	bool empty() {
		if (size() == 0) {
			return true;
		}
		else
			return false;
	} // ť�� ����ִ��� ���� �Ǵ�

	void enqueue(int data) {
		if (size() == capacity - 1) {
			return;
		} // exception handling
		arr[rearidx] = data; // queue�� �ڿ� ������ ����
		rearidx = (rearidx + 1) % capacity; // rearidx�� 1 ����,rearidx�� capacity�� �Ѿ�� �ٽ� 0
		arrsize++; // ť ������ ����
	} // ť�� �ڿ� ������ ����

	void dequeue() {
		if (empty()) {
			return;
		} // exception handling
		frontidx = (frontidx + 1) % capacity; // frontidx�� 1 ����, frontidx�� capacity�� �Ѿ�� �ٽ� 0
		arrsize--; // ť ������ ����
	} // ť�� �� ������ ����

	int front() {
		if (empty()) {
			return;
		}
		return arr[frontidx];
	} // frontidx�� ������ ����
};

int main() {
	int n, k;
	cin >> n >> k;
	queue q(n + 1);

	for (int i = 1; i <= n; i++) {
		q.enqueue(i);
	} // 1���� n���� ť�� ����

	cout << "<";

	for(int i = 1; !q.empty(); i++) {
		if (q.size() == 1) {
			cout << q.front();
			q.dequeue();
			break;
		} // ť ����� 1�̶�� ,�� ������� �ʰ� �ݺ��� Ż��
		if (i % k == 0) {
			cout << q.front() << ", ";
			q.dequeue();
			continue;
		} // i�� k�� ���� �������� 0�̶��, ť�� �տ��� ������ ����


		int temp = q.front(); // ť�� �� �� ������ ����
		q.dequeue(); // ť�� �� �� ������ ����
		q.enqueue(temp); // ť�� �� �����͸� �ڷ� ����
	} // �����ؾߵ� �ε����� �����͸� �����, �� �����͵��� ť�� �ڷ� ����
	// ���������� ������ �ε����� �����ϸ� ������ ����
	cout << ">";
}