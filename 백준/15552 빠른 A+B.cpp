/*
본격적으로 for문 문제를 풀기 전에 주의해야 할 점이 있다.
입출력 방식이 느리면 여러 줄을 입력받거나 출력할 때 시간초과가 날 수 있다는 점이다.

C++을 사용하고 있고 cin/cout을 사용하고자 한다면, cin.tie(NULL)과 sync_with_stdio(false)를 둘 다 적용해 주고,
endl 대신 개행문자(\n)를 쓰자.
단, 이렇게 하면 더 이상 scanf/printf/puts/getchar/putchar 등 C의 입출력 방식을 사용하면 안 된다.

Java를 사용하고 있다면, Scanner와 System.out.println 대신 BufferedReader와 BufferedWriter를 사용할 수 있다.
BufferedWriter.flush는 맨 마지막에 한 번만 하면 된다.

Python을 사용하고 있다면, input 대신 sys.stdin.readline을 사용할 수 있다.
단, 이때는 맨 끝의 개행문자까지 같이 입력받기 때문에 문자열을 저장하고 싶을 경우 .rstrip()을 추가로 해 주는 것이 좋다.
*/

#include <iostream>

using namespace std;




int main() {
	cin.tie(NULL); // cin과 cout의 묶음을 풀어준다
	ios_base::sync_with_stdio(false); // C와 C++의 버퍼를 분리한다
	// 이를 사용하면 더이상 stdin/stdout과 맞춰 줄 필요가 없어지므로 속도가 빨라진다
	// cin, cout을 사용할 때이고, scanf/printf는 충분히 처리 속도가 빠르다
	int testcase;
	int a, b;

	cin >> testcase; 
	for (int i = 1; i <= testcase; i++) {
		cin >> a >> b;
		cout << a + b << "\n"; // endl은 개행문자를 출력하며 출력 버퍼를 비우는데, 이 처리속도가 매우느리다
		// 따라서 "\n"을 사용함으로 시간을 줄일 수 있다.
	}	

	return 0;
}

