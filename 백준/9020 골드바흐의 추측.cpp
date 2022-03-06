/*
1보다 큰 자연수 중에서  1과 자기 자신을 제외한 약수가 없는 자연수를 소수라고 한다.
예를 들어, 5는 1과 5를 제외한 약수가 없기 때문에 소수이다.
하지만, 6은 6 = 2 × 3 이기 때문에 소수가 아니다.

골드바흐의 추측은 유명한 정수론의 미해결 문제로,
2보다 큰 모든 짝수는 두 소수의 합으로 나타낼 수 있다는 것이다. 이러한 수를 골드바흐 수라고 한다.
또, 짝수를 두 소수의 합으로 나타내는 표현을 그 수의 골드바흐 파티션이라고 한다.
예를 들면, 4 = 2 + 2, 6 = 3 + 3, 8 = 3 + 5, 10 = 5 + 5, 12 = 5 + 7, 14 = 3 + 11, 14 = 7 + 7이다.
10000보다 작거나 같은 모든 짝수 n에 대한 골드바흐 파티션은 존재한다.

2보다 큰 짝수 n이 주어졌을 때, n의 골드바흐 파티션을 출력하는 프로그램을 작성하시오.
만약 가능한 n의 골드바흐 파티션이 여러 가지인 경우에는 두 소수의 차이가 가장 작은 것을 출력한다.
*/

#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t, n;

	cin >> t;
	bool prime[10001];
	memset(prime, true, sizeof(prime));

	for (int i = 2; i <= 10000; i++) {
		for (int j = 2; i * j <= 10000; j++) {
			prime[i * j] = false;
		}
	} // 에라토스테네스의 체

	for (int i = 0; i < t; i++) {
		cin >> n;
		int index1 = 0;
		int	index2 = 0; // 두 index를 더해서 n이 될 때, 두 index를 저장한다
	
		for (int i = n / 2; i >= 2; i--) { 
			if (prime[i] == true) {
				int temp = n; // n은 변하면 안되는 수이므로, temp에 저장한다
				temp -= i; // temp에서 n의 중간 값과 가장 가까운 소수인 i를 뺀다
				if (prime[temp] == true) {
					index1 = i;
					index2 = temp;
					break;
				} // temp에서 i를 뺀 값이 소수일 경우, 가장 차가 작은 두 수의 합이 n이 된다.
			}
		} // ※두 수의 합의 차가 가장 작을 때는, 두 수 중, 한 수가 n의 중간 값에 가장 가까이 있을 때이다.
		cout << index1 << " " << index2 << "\n";
	}


}