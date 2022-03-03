/*
정수 N개로 이루어진 수열 A와 정수 X가 주어진다.
이때, A에서 X보다 작은 수를 모두 출력하는 프로그램을 작성하시오.
*/

#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, x;
	int num;
	cin >> n >> x;
	int *a = new int[n]; // int 타입 포인터 a에 n의 크기만큼의 동적 배열을 할당한다

	for (int i = 0; i < n; i++) {
		cin >> num;
		a[i] = num;
	} // 배열의 각 index를 n개의 정수로 초기화한다 

	for (int i = 0; i < n; i++) {
		if (a[i] < x)
			cout << a[i] << " ";
	} // 배열에 있는 모든 index들의 값을 if문으로 검사하여 x보다 낮은 값을 출력한다

	delete a; // 동적 할당하였던 a의 메모리를 해제한다

	return 0;
}