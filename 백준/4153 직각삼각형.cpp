/*
과거 이집트인들은 각 변들의 길이가 3, 4, 5인 삼각형이 직각 삼각형인것을 알아냈다.
주어진 세변의 길이로 삼각형이 직각인지 아닌지 구분하시오.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int len1, len2, len3;

	while (true) {
		cin >> len1 >> len2 >> len3;

		if (len1 == 0 && len2 == 0 && len3 == 0)
			break;
		if (pow(len1, 2) + pow(len2, 2) == pow(len3, 2))
			cout << "right\n";
		else if (pow(len2, 2) + pow(len3, 2) == pow(len1, 2))
			cout << "right\n";
		else if (pow(len1, 2) + pow(len3, 2) == pow(len2, 2))
			cout << "right\n";
		// 두 개의 변의 제곱을 더하여 나머지 한 변의 제곱과 같다면 이는 직각삼각형이다 (피타고라스의 정리)
		else
			cout << "wrong\n";
	}
}