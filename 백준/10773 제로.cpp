/*
나코더 기장 재민이는 동아리 회식을 준비하기 위해서 장부를 관리하는 중이다.

재현이는 재민이를 도와서 돈을 관리하는 중인데,
애석하게도 항상 정신없는 재현이는 돈을 실수로 잘못 부르는 사고를 치기 일쑤였다.

재현이는 잘못된 수를 부를 때마다 0을 외쳐서, 
가장 최근에 재민이가 쓴 수를 지우게 시킨다.

재민이는 이렇게 모든 수를 받아 적은 후 그 수의 합을 알고 싶어 한다. 재민이를 도와주자!
*/

#include <iostream>

using namespace std;

class stack {
private:
	int t;
	int* arr;

public:
	stack(int k) {
		t = -1; // stack의 맨 위(top)의 index를 저장할 변수
		arr = new int[k]; 
		for (int i = 0; i < k; i++) {
			arr[i] = 0;
		} // arr의 크기는 k를 넘지 않는다.
	} // constructor, 멤버 변수 초기화

	bool empty() {
		if (t == -1) {
			return true;
		}
		else
			return false;
	} // stack이 비어있다면 true, 아니라면 false를 반환

	int size() {
		return t + 1;
	} // stack의 사이즈를 반환

	void push(int data) {
		if (data == 0) {
			pop();
		}
		else {
			arr[t + 1] = data;
			t++;
		}
	} // 입력된 수가 0이라면 pop()을 실행하고, 아니라면 top의 위에 수를 추가

	void pop() {
		t--;
	} // stack의 top에 있는 요소를 pop

	int sum() {
		int sum = 0;
		for (int i = 0; i < size(); i++) {
			sum += arr[i];
		}
		return sum;
	} // stack의 모든 요소들의 합을 구하는 함수
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