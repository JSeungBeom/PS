/*
괄호 문자열(Parenthesis String, PS)은 두 개의 괄호 기호인 ‘(’ 와 ‘)’ 만으로 구성되어 있는 문자열이다.
그 중에서 괄호의 모양이 바르게 구성된 문자열을 올바른 괄호 문자열(Valid PS, VPS)이라고 부른다.
한 쌍의 괄호 기호로 된 “( )” 문자열은 기본 VPS 이라고 부른다.
만일 x 가 VPS 라면 이것을 하나의 괄호에 넣은 새로운 문자열 “(x)”도 VPS 가 된다.
그리고 두 VPS x 와 y를 접합(concatenation)시킨 새로운 문자열 xy도 VPS 가 된다.
예를 들어 “(())()”와 “((()))” 는 VPS 이지만 “(()(”,
“(())()))” , 그리고 “(()” 는 모두 VPS 가 아닌 문자열이다.

여러분은 입력으로 주어진 괄호 문자열이 VPS 인지 아닌지를 판단해서
그 결과를 YES 와 NO 로 나타내어야 한다.
*/

#include <iostream>

using namespace std;

class stack {
private:
	int topIndex;
	char* arr;
	int capacity;
	bool flag; // 문자열이 VPS인지 판단하는 변수

public:
	stack(int capacity) {
		this->capacity = capacity;
		arr = new char[capacity];
		topIndex = -1;
		flag = false;
	} // 스택의 멤버 변수 초기화

	int size() {
		return topIndex + 1;
	} // 스택의 사이즈를 리턴

	bool empty() {
		if (size() == 0) {
			return true;
		}
		else
			return false;
	} // 스택이 비었는지 판단

	bool vps() {
		if (flag == true || !empty()) {
			return true;
		}
		else
			return false;
	}


	void push(char data) {
		if (size() == capacity) {
			return;
		} // 스택의 사이즈가 배열의 크기와 같은 경우

		if (data == '(') {
			arr[++topIndex] = data;
		} // topIndex를 1 증가시키고, 해당 인덱스에 데이터를 삽입
		// 여는 괄호는 뒤의 닫는 괄호에 따라 VPS가 결정되므로, 일단 스택에 push한다
		else if (data == ')') {
			if (empty()) {
				flag = true;
				return;
			}
			pop();
		} // 닫는 괄호를 만날때마다, 스택에 쌓인 여는 괄호를 pop()한다
		// 이 과정에서, 스택의 크기가 0인 경우, VPS가 아니므로 false를 리턴
	}
	
	char top() {
		if (empty()) {
			exit(1);
		}
		return arr[topIndex];
	}

	void pop() {
		if (empty()) {
			exit(1);
		}
		topIndex--;
	}
};

int main() {
	int t;

	cin >> t;

	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;
		stack st(s.length());
		for (int j = 0; j < s.length(); j++) {
			st.push(s[j]);
		}
		if (st.vps()) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
		}
	}

}

/* 
ex) ((()) 닫는 괄호가 부족한 경우 :
모든 문자열에 대한 검사가 끝났지만, 스택에 데이터가 남아있는 경우
ex) ())) 여는 괄호가 부족한 경우 :
pop()을 수행하는 과정에서, 스택에 데이터가 없는 경우
ex) )( 괄호의 갯수는 맞지만, 짝이 맞지 않는 경우 :
여는 괄호가 부족한 경우와 동일하다
*/