/*
어떤 양의 정수 X의 각 자리가 등차수열을 이룬다면,
그 수를 한수라고 한다.
등차수열은 연속된 두 개의 수의 차이가 일정한 수열을 말한다.
N이 주어졌을 때, 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력하는 프로그램을 작성하시오.
*/

#include <iostream>

using namespace std;

int han(int n) {

	int count = 0; // 한수의 개수를 저장할 변수

	for (int i = 1; i <= n; i++) {
		if (i >= 1 && i <= 99) {
			count++;
			continue;
		} // 1부터 99의 수는 항상 한수이므로 count를 1 더하고 continue로 넘어간다

		else if (i == 1000) {
			break;
		} // 최대 1000까지의 수 중, 1000은 한수가 아니므로 for문을 빠져나간다

		else {
			int arr[3];
			int temp = i;
			for (int j = 0; j < 3; j++) {
				arr[j] = temp % 10;
				temp /= 10;
			} // 배열의 각 자리를 초기화한다
			if (arr[0] - arr[1] == arr[1] - arr[2])
				count++;
			// 한수가 맞으면 count를 1 더한다
		} // 1부터 1000까지의 수이므로, 사실상 3자리의 수만 생각하면 된다
	}

	return count;
} // 한수의 개수를 구하는 함수

int main() {
	int n;

	cin >> n;

	cout << han(n) << endl;

	return 0;
}