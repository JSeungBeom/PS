#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string str="";
	string input;
	while (true) {
		getline(cin, input);
		if (cin.eof() == true) {
			break;
		}
		str.append(input);
        		str.append("\n");
	}
	cout << str;
}