/*
���ڴ� ���� ����̴� ���Ƹ� ȸ���� �غ��ϱ� ���ؼ� ��θ� �����ϴ� ���̴�.

�����̴� ����̸� ���ͼ� ���� �����ϴ� ���ε�,
�ּ��ϰԵ� �׻� ���ž��� �����̴� ���� �Ǽ��� �߸� �θ��� ��� ġ�� �Ͼ�����.

�����̴� �߸��� ���� �θ� ������ 0�� ���ļ�, 
���� �ֱٿ� ����̰� �� ���� ����� ��Ų��.

����̴� �̷��� ��� ���� �޾� ���� �� �� ���� ���� �˰� �;� �Ѵ�. ����̸� ��������!
*/

#include <iostream>

using namespace std;

class stack {
private:
	int t;
	int* arr;

public:
	stack(int k) {
		t = -1; // stack�� �� ��(top)�� index�� ������ ����
		arr = new int[k]; 
		for (int i = 0; i < k; i++) {
			arr[i] = 0;
		} // arr�� ũ��� k�� ���� �ʴ´�.
	} // constructor, ��� ���� �ʱ�ȭ

	bool empty() {
		if (t == -1) {
			return true;
		}
		else
			return false;
	} // stack�� ����ִٸ� true, �ƴ϶�� false�� ��ȯ

	int size() {
		return t + 1;
	} // stack�� ����� ��ȯ

	void push(int data) {
		if (data == 0) {
			pop();
		}
		else {
			arr[t + 1] = data;
			t++;
		}
	} // �Էµ� ���� 0�̶�� pop()�� �����ϰ�, �ƴ϶�� top�� ���� ���� �߰�

	void pop() {
		t--;
	} // stack�� top�� �ִ� ��Ҹ� pop

	int sum() {
		int sum = 0;
		for (int i = 0; i < size(); i++) {
			sum += arr[i];
		}
		return sum;
	} // stack�� ��� ��ҵ��� ���� ���ϴ� �Լ�
};

int main() {
	int k;
	cin >> k;
	stack s(k);

	for (int i = 0; i < k; i++) {
		int num;
		cin >> num;
		s.push(num);
	}

	cout << s.sum() << endl;

	return 0;
}