#include <iostream>
#include<string>
using namespace std;

string w;

string reverse(string::iterator& it) {
	char head = *it;
	it++;

	if (head == 'b' || head == 'w') return string(1, head);

	string ul = reverse(it);
	string ur = reverse(it);
	string ll = reverse(it);
	string lr = reverse(it);

	return string("x") + ll + lr + ul + ur;
}
int main() {

	int cases;
	cin >> cases;

	for (int i = 0; i < cases; i++) {
		cin >> w;
		string::iterator it = w.begin();
		string reversed = reverse(it);
		cout << reversed << endl;
	}

	return 0;
}

