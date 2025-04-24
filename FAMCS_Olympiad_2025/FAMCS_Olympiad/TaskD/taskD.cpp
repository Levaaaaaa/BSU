#include <iostream>
#include <string>

using namespace std;

int dir[26];

void init_d() {
	for (int i = 0; i < 26; i+= 2) {
		dir[i] = i + 1;
		dir[i + 1] = i;
	}
}

string f(string message) {
	for (int i = 0; i < message.size(); i++) {
		message[i] = 'a' + dir[message[i] - 'a'];
	}

	return message;
}
int main() {
	init_d();
	int t;
	cin >> t;
	string mess;
	for (int i = 0; i < t; i++) {
		cin >> mess;
		cout << f(mess) << "\n";
	}
	return 0;
}