/*
자연수 M과 N이 주어질 때 M이상 N이하의 자연수 중 소수인 것을 모두 골라
이들 소수의 합과 최솟값을 찾는 프로그램을 작성하시오.

예를 들어 M=60, N=100인 경우 60이상 100이하의 자연수 중 소수는
61, 67, 71, 73, 79, 83, 89, 97 총 8개가 있으므로, 이들 소수의 합은 620이고, 최솟값은 61이 된다.
*/

#include <iostream>

using namespace std;

int main() {
	int m, n;

	cin >> m;
	cin >> n;

	int arr[10000] = { 0, }; // 배열을 모두 0으로 초기화

	for (int i = m; i <= n; i++) {
		arr[i] = i;
	} // 배열의 i번째 인덱스에 값 i로 초기화

	for (int i = m; i <= n; i++) {
		if (arr[i] == 1) {
			arr[i] = 0;
			continue;
		} // 1은 소수가 아니므로 0을 대입한다
		for (int j = 2; j < arr[i]; j++) {
			if (arr[i] % j == 0) {
				arr[i] = 0;
				break;
			}
		} // 소수는 1과 자신으로만 나눠지는 수이므로, 2부터 자신 - 1까지
		// 반복하며 나누어 떨어지면 해당 index에 0을 대입한다
	} // m부터 n까지 반복하며 소수가 아닌 index는 0을 대입한다


	int min = 10001; // m, n은 둘다 10000이하의 자연수이므로 min을 10001로 초기화
	int sum = 0;

	for (int i = m; i <= n; i++) {
		if (arr[i] < min && arr[i] != 0) {
			min = arr[i];
		} // i번째 값이 mih보다 작고, 0이 아닌 경우(소수인 경우)에 min값을 i번째 값을 대입한다
		sum += arr[i]; // 소수들의 합을 구한다 
	}

	if (sum == 0) {
		cout << -1 << endl;
	} // 합이 0이라면, 소수가 없는 경우이므로 -1을 출력

	else {
		cout << sum << endl
			<< min << endl;
	}
}