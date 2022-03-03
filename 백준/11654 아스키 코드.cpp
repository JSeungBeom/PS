/*
알파벳 소문자, 대문자, 숫자 0-9중 하나가 주어졌을 때,
주어진 글자의 아스키 코드값을 출력하는 프로그램을 작성하시오.
*/

#include <iostream>

using namespace std;

int main() {
	char a;
	cin >> a;

	cout << static_cast<int> (a) << endl; // static_cast를 활용하여 char 타입의 a를 int 타입으로 변환

	return 0;
}
