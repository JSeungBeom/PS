/*
예전에는 운영체제에서 크로아티아 알파벳을 입력할 수가 없었다.
따라서, 다음과 같이 크로아티아 알파벳을 변경해서 입력했다.

크로아티아 알파벳	변경
		č			c=
		ć			c-
		dž			dz=
		đ			d-
		lj			lj
		nj			nj
		š			s=
		ž			z=
				
예를 들어, ljes=njak은 크로아티아 알파벳 6개(lj, e, š, nj, a, k)로 이루어져 있다.
단어가 주어졌을 때, 몇 개의 크로아티아 알파벳으로 이루어져 있는지 출력한다.

dž는 무조건 하나의 알파벳으로 쓰이고, d와 ž가 분리된 것으로 보지 않는다.
lj와 nj도 마찬가지이다. 위 목록에 없는 알파벳은 한 글자씩 센다.
*/

#include <iostream>
#include <string.h>
using namespace std;

int main() {
	char word[101];
	int count = 0;

	cin >> word; 

	for (int i = 0; i < strlen(word); i++) {
		if (word[i] == 'c' && word[i + 1] == '-')
		{
			count++;
			i += 1;
			continue;
		}
		else if (word[i] == 'c' && word[i + 1] == '=')
		{
			count++;
			i += 1;
			continue;
		}
		else if (word[i] == 'd' && word[i + 1] == 'z' && word[i + 2] == '=')
		{
			count++;
			i += 2;
			continue;
		}
		else if (word[i] == 'd' && word[i + 1] == '-')
		{
			count++;
			i += 1;
			continue;
		}
		else if (word[i] == 'l' && word[i + 1] == 'j')
		{
			count++;
			i += 1;
			continue;
		}
		else if (word[i] == 'n' && word[i + 1] == 'j')
		{
			count++;
			i += 1;
			continue;
		}
		else if (word[i] == 's' && word[i + 1] == '=')
		{
			count++;
			i += 1;
			continue;
		}
		else if (word[i] == 'z' && word[i + 1] == '=')
		{
			count++;
			i += 1;
			continue;
		} // 연속된 문자가 크로아티아 알파벳인지 판단하고, 맞는 경우 count를 1 더하고 그 문자를 넘어가서 다시 검사한다 
		else
			count++; // 하나의 문자도 크로아티아 알파벳이므로, count를 1 더해준다.
	}

	cout << count << endl;
}