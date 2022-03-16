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

class stack {
private:
	int stck[10000];
	int	stacksize; // 스택의 size를 계산할 변수

public:
	stack() {
		stacksize = 0;
		for (int i = 0; i < 10000; i++) {
			stck[i] = 0;
		}
	} // 멤버변수 초기화 constructor

	void empty() {
		if (stacksize == 0) {
			cout << 1 << endl;
		}
		else {
			cout << 0 << endl;
		}
	} 
	void push(int x) {
		stck[stacksize] = x;
		stacksize++; 
 	} // 스택의 맨 위(stacksize)에 데이터를 추가하고, 사이즈를 증가

	void pop() {
		if (stacksize == 0) {
			cout << -1 << endl;
			return;
		}
		cout << stck[stacksize - 1] << endl;
		stck[stacksize - 1] = 0;
		stacksize--;
	} // 스택의 맨 위 데이터를 0으로 변경(삭제)하고, 사이즈를 감소

	void top() {
		if (stacksize == 0) {
			cout << -1 << endl;
			return;
		}
		else {
			cout << stck[stacksize - 1] << endl;
		} 
 	} // 스택의 맨 위 데이터를 출력

	void size() {
		cout << stacksize << endl;
	} // 스택의 사이즈 출력
};

int main() {
	int n;
	stack st;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		int x;
		if (s == "push") {
			cin >> x;
			st.push(x);
		}
		else if (s == "top") {
			st.top();
		}
		else if (s == "size") {
			st.size();
		}
		else if (s == "empty") {
			st.empty();
		}
		else if (s == "pop") {
			st.pop();
		}
		else
			break;
	}
}

// 배열을 이용한 간단한 stack 구현