/*
대학생 새내기들의 90%는 자신이 반에서 평균은 넘는다고 생각한다.
당신은 그들에게 슬픈 진실을 알려줘야 한다.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int c, n;


	cin >> c; // 테스트케이스 입력

	for (int i = 0; i < c; i++) {
		cin >> n; // 학생의 수 입력

		double* score = new double[n]; // 학생의 수 만큼 동적 배열을 생성한다
		double sum = 0, avg = 0;
		double stdnum = 0;

		for (int j = 0; j < n; j++) {
			cin >> score[j];
			sum += score[j];
		} // 각 학생의 점수를 입력받고 그 합을 구한다

		avg = sum / n; // 평균을 구한다

		for (int j = 0; j < n; j++) {
			if (score[j] > avg) {
				stdnum++;
			}
		} // 평균이 넘는 학생의 수를 구한다

		delete []score; // 동적 배열의 할당되었던 메모리를 해제한다

		cout << fixed << setprecision(3) << (stdnum / n) * 100 << "%\n";
		// 평균이 넘는 학생의 비율을 소수점 3자리수 까지 반올림하여 출력한다. 
	}

	return 0;
}