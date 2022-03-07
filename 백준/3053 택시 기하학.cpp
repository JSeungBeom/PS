/*
19세기 독일 수학자 헤르만 민코프스키는 비유클리드 기하학 중 택시 기하학을 고안했다.
택시 기하학에서 두 점 T1(x1,y1), T2(x2,y2) 사이의 거리는 다음과 같이 구할 수 있다.

D(T1,T2) = |x1-x2| + |y1-y2|

두 점 사이의 거리를 제외한 나머지 정의는 유클리드 기하학에서의 정의와 같다.
따라서 택시 기하학에서 원의 정의는 유클리드 기하학에서 원의 정의와 같다.
원: 평면 상의 어떤 점에서 거리가 일정한 점들의 집합

반지름 R이 주어졌을 때, 유클리드 기하학에서 원의 넓이와, 
택시 기하학에서 원의 넓이를 구하는 프로그램을 작성하시오.
*/
#define _USE_MATH_DEFINES 

#include <iostream>
#include <math.h> // M_PI(파이 상수)를 사용하기 위한 헤더파일 
#include <iomanip>


using namespace std;

int main() {
	double r;
	cin >> r;

	cout.precision(6);
	cout << fixed <<  r * r * M_PI << "\n"; 
	// 유클리드 기하학에서의 원 (흔히 알고 있는 원)
	cout << fixed << 2 * r * r << "\n";
	// 택시 기하학에서의 원은, 대각선의 길이가 2r인 마름모라고 할 수 있다.
	return 0;
}