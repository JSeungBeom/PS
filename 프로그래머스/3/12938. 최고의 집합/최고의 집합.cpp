#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
	vector<int> answer;
	
	int div = s / n;
	int mod = n - (s % n);

	if (!div) {
		return { -1 };
	}

	for (int i = 0; i < mod; i++) {
		answer.push_back(div);
	}

	for (int i = mod; i < n; i++) {
		answer.push_back(div + 1);
	}
	
	return answer;
}