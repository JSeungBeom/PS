/*
시험 점수를 입력받아 90 ~ 100점은 A, 80 ~ 89점은 B, 70 ~ 79점은 C,
60 ~ 69점은 D, 나머지 점수는 F를 출력하는 프로그램을 작성하시오.
*/

#include <iostream>

using namespace std;

int main() {

	int score;

	cin >> score;

	if (score >= 90) {
		cout << "A" << endl;
	}
	else if (score >= 80) {
		cout << "B" << endl;
	}
	else if (score >= 70) {
		cout << "C" << endl;
	}

	else if (score >= 60) {
		cout << "D" << endl;
	} // else if 문을 사용함으로써 등급의 최고 점수가 제한된다.

	else 
		cout << "F" << endl; // 60점 미만의 점수는 else 문으로 처리

	return 0;
}