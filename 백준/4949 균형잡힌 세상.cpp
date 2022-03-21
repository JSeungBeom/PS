/*
세계는 균형이 잘 잡혀있어야 한다. 양과 음, 빛과 어둠 그리고 왼쪽 괄호와 오른쪽 괄호처럼 말이다.

정민이의 임무는 어떤 문자열이 주어졌을 때,
괄호들의 균형이 잘 맞춰져 있는지 판단하는 프로그램을 짜는 것이다.

문자열에 포함되는 괄호는 소괄호("()") 와 대괄호("[]")로 2종류이고,
문자열이 균형을 이루는 조건은 아래와 같다.

모든 왼쪽 소괄호("(")는 오른쪽 소괄호(")")와만 짝을 이뤄야 한다.
모든 왼쪽 대괄호("[")는 오른쪽 대괄호("]")와만 짝을 이뤄야 한다.
모든 오른쪽 괄호들은 자신과 짝을 이룰 수 있는 왼쪽 괄호가 존재한다.
모든 괄호들의 짝은 1:1 매칭만 가능하다. 즉, 괄호 하나가 둘 이상의 괄호와 짝지어지지 않는다.
짝을 이루는 두 괄호가 있을 때, 그 사이에 있는 문자열도 균형이 잡혀야 한다.
정민이를 도와 문자열이 주어졌을 때 균형잡힌 문자열인지 아닌지를 판단해보자.
*/

#include <iostream>
#include <string.h>
#include <string>

using namespace std;

class stack {
private:
	char* arr; // char 타입 스택을 저장할 배열
	int topIndex; // top에 있는 데이터를 저장하고 있는 index
	int capacity; // 배열의 최대 크기
	bool flag = false; // 괄호의 짝 여부 판단

public:
	stack(int capacity) {
		this->capacity = capacity;
		arr = new char[capacity];
		topIndex = -1;
	} // 멤버 변수의 초기화
	
	int size() {
		return topIndex + 1;
	} // 스택의 크기 리턴

	bool empty() {
		if (size() == 0) {
			return true;
		}
		else
			return false;
	} // 스택이 비었는지 판단

	bool check() {
		if (!empty() || flag == true) {
			return true;
		}
		else
			return false;
	}

	void push(char data) {
		if (capacity == size()) {
			return;
		}
		if (data == '(' || data == '[') {
			arr[++topIndex] = data;
		} // 괄호가 왼쪽 괄호일 경우 스택에 추가
		else if (data == ')') {
			if (empty()) {
				flag = true;
				return;
			} // 스택이 비었을 경우, 짝이 맞지 않는 경우이므로 flag를 true로 변경하고 리턴
			if (top() == '(') {
				pop();
			} // 오른쪽 소괄호가 입력되었다면, 왼쪽 소괄호가 stack의 top에 있으면 pop 수행
			else {
				flag = true;
				return;
			} // 괄호의 모양이 맞지 않는 경우 flag를 true로 변경하고 리턴
		} 
		else if (data == ']') {
			if (empty()) {
				flag = true;
				return;
			} // 스택이 빈 경우

			if (top() == '[') {
				pop();
			}
			else {
				flag = true;
				return;
			}
		}
	}



	char top() {
		if (empty()) {
			exit(1);
		}
		return arr[topIndex];
	} // stack의 top 데이터를 리턴

	void pop() {
		if (empty()) {
			return;
		}
		topIndex--;
	} // 스택의 top 데이터를 삭제
};

int main() {
	while (true) {
		string s;
		getline(cin, s);
		// getline(cin, string) : 스트링을 공백 포함하여 입력받는 함수

		if (s == ".") {
			return 0;
		}

		stack st(s.length());
		for (int i = 0; i < s.length(); i++) {
			st.push(s[i]);
		}
		if (st.check()) {
			cout << "no" << endl;
		}
		else
			cout << "yes" << endl;

	}
}