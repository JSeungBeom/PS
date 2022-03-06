/*
한수는 지금 (x, y)에 있다. 직사각형은 각 변이 좌표축에 평행하고,
왼쪽 아래 꼭짓점은 (0, 0), 오른쪽 위 꼭짓점은 (w, h)에 있다.
직사각형의 경계선까지 가는 거리의 최솟값을 구하는 프로그램을 작성하시오.
*/

#include <iostream>

using namespace std;

int main() {
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	int min = 10000;

	int up = h - y; // 위로 갔을 때의 거리
	int down = y; // 아래로 갔을 때의 거리
	int left = x; // 왼쪽으로 갔을 때의 거리
	int right = w - x; // 오른쪽으로 갔을 때의 거리
	int distance[4] = { up, down, left, right }; // 각 거리를 저장할 배열
	for (int i = 0; i < 4; i++) {
		if (distance[i] < min)
			min = distance[i];
	} // 가장 짧은 거리를 min에 저장

	cout << min << "\n";

	return 0;
}
/* 
경계선까지의 거리를 구할 때, 위 / 아래 / 왼쪽 / 오른쪽으로의 거리만 구하는 이유는,
점과 점 사이를 연결했을 때, 직각인 경우 가장 짧은 경로이기 때문이다.
*/