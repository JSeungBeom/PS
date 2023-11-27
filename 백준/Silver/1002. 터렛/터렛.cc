/*
조규현과 백승환은 터렛에 근무하는 직원이다.
하지만 워낙 존재감이 없어서 인구수는 차지하지 않는다.
다음은 조규현과 백승환의 사진이다.

이석원은 조규현과 백승환에게 상대편 마린(류재명)의 위치를 계산하라는 명령을 내렸다.
조규현과 백승환은 각각 자신의 터렛 위치에서 현재 적까지의 거리를 계산했다.

조규현의 좌표 (x1, y1)와 백승환의 좌표 (x2, y2)가 주어지고,
조규현이 계산한 류재명과의 거리 r1과 백승환이 계산한 류재명과의 거리 r2가 주어졌을 때,
류재명이 있을 수 있는 좌표의 수를 출력하는 프로그램을 작성하시오.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int t;
	cin >> t;

	int x1, y1, r1, x2, y2, r2;
	for (int i = 0; i < t; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		int longer = r1 > r2 ? r1 : r2; // 더 긴 반지름을 저장(내접과 외접을 판단할 때에 사용)
		int shorter = r1 < r2 ? r1 : r2; // 더 짧은 반지름을 저장

		double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)); // 중심 좌표 간의 거리
		if (x1 == x2 && y1 == y2 && r1 == r2)
			cout << -1 << "\n";
		// 원의 중심 좌표와 반지름이 같을 때(원이 완전히 겹칠 때) 있을 수 있는 위치가 무한대이므로, -1 출력
		else if (longer > distance + shorter) {
			cout << 0 << "\n";
		}

		else if (longer == distance + shorter) {
			cout << 1 << "\n";
		}
		// 원의 내접
		else {
			if (r1 + r2 == distance)
				cout << 1 << "\n";
			else if (r1 + r2 < distance)
				cout << 0 << "\n";
			else {
				cout << 2 << "\n";
			}
		} // 원의 외접
	}
	
}