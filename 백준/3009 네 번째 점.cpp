/*
세 점이 주어졌을 때, 축에 평행한 직사각형을 만들기 위해서 필요한 네 번째 점을 찾는 프로그램을 작성하시오.
*/

#include <iostream>

using namespace std;

int main() {
	int x1, x2, x3, y1, y2, y3;
	int x4, y4;
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;

	if (x1 == x2)
		x4 = x3;
	else if (x1 == x3)
		x4 = x2;
	else if (x2 == x3)
		x4 = x1;

	if (y1 == y2)
		y4 = y3;
	else if (y1 == y3)
		y4 = y2;
	else if (y2 == y3)
		y4 = y1;
	// x좌표나 y좌표 2개가 동일할 시, 그 x좌표와 y좌표는 어느 한 변을 구성하도록 고정된 것이므로,
	// 다른 1개의 x좌표나 y좌표를 4번째 점에 대입하여 모든 변을 구성하도록 하여야한다
	cout << x4 << " " << y4 << "\n";

	return 0;
}