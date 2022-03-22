/*
스택 (stack)은 기본적인 자료구조 중 하나로, 컴퓨터 프로그램을 작성할 때 자주 이용되는 개념이다.
스택은 자료를 넣는 (push) 입구와 자료를 뽑는 (pop) 입구가 같아
제일 나중에 들어간 자료가 제일 먼저 나오는 (LIFO, Last in First out) 특성을 가지고 있다.

1부터 n까지의 수를 스택에 넣었다가 뽑아 늘어놓음으로써, 하나의 수열을 만들 수 있다.
이때, 스택에 push하는 순서는 반드시 오름차순을 지키도록 한다고 하자.
임의의 수열이 주어졌을 때 스택을 이용해 그 수열을 만들 수 있는지 없는지, 
있다면 어떤 순서로 push와 pop 연산을 수행해야 하는지를 알아낼 수 있다.
이를 계산하는 프로그램을 작성하라.
*/

#include <iostream>

using namespace std;

class stack {
private:
	int* arr;
	int capacity;
	int topIndex;
	char* ar; 

public:
	stack(int capacity) {
		this->capacity = capacity;
		arr = new int[capacity];
		ar = new char[capacity];
		topIndex = -1;
	}  // 멤버변수 초기화

	int size() {
		return topIndex + 1;
	} // 스택의 사이즈(topIndex+1)을 리턴

	bool empty() {
		if (size() == 0) {
			return true;
		}
		else
			return false;
	} // 스택이 비었다면 true, 아니라면 false를 리턴

	void push(int data) {
		if (size() == capacity) {
			return;
		} // 스택이 배열의 크기를 넘어서는 경우 exception

		arr[++topIndex] = data; // topIndex를 1 증가시키고, 해당 인덱스에 데이터를 삽입
	}

	void pop() {
		if (empty()) {
			return;
		} // 스택이 비어있는 경우 종료
		topIndex--;  // 스택의 topIndex를 1 감소
	}

	int top() {
		if (empty()) {
			return -1;
		} // 스택이 비어있는 경우 종료
		return arr[topIndex];
	} // 스택의 top 데이터를 리턴

}; // 배열을 이용한 stack의 모든 기능 구현에 있어서, 공간복잡도는 O(N)(N은 배열의 크기)
// 시간복잡도는 O(1)이다

int main() {
	int n;
	cin >> n;

	stack st(n); // 객체 생성
	char check[1000000];// 부호를 저장할 배열
	int num = 1; // 스택 안에 삽입할 int 타입 데이터
	int checknum = -1; // 부호 저장 배열의 index값

	for (int i = 0; i < n; i++) {
		int data;
		cin >> data;

		if (num <= data) {
			for (num; num <= data; num++) {
				st.push(num);
				check[++checknum] = '+';
			} // num이 data 값이 될 때까지 stack에 push
			st.pop(); // num이 data값이 되었다면, stack에서 pop
			check[++checknum] = '-';
		}
		else {
			if (st.top() < data) {
				check[++checknum] = 'N';
				break;
			} // 스택의 top 데이터보다, 입력된 데이터가 큰 경우 
				st.pop(); // 입력받은 데이터보다 num이 크다면, pop
				check[++checknum] = '-';
		}
	}

	for (int i = 0; i < checknum + 1; i++) {
		if (check[i] == 'N') {
			cout << "NO";
			return 0;
		}
	} // 부호 배열에 N이 있다면, 수열이 될 수 없으므로 NO를 출력하고 종료

	for (int i = 0; i < checknum + 1; i++) {
		cout << check[i] << "\n";
	} // 부호 배열의 요소들을 출력
}