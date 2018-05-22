#include <string>
#include <iostream>
#include <vector>
using namespace std;
string s;
string reverse_quad(string::iterator& i) {
	
	char c = *i;
	i++;
	if (c == 'b' || c == 'w') {

		return string(1,*i);
	}
	else if (c=='x') {

		string a = reverse_quad(i);
		string b = reverse_quad(i);
		string c = reverse_quad(i);
		string d = reverse_quad(i);

		//s="x"+c + d + a + b;
		return string("x") + c + d + a + b;
	}

}

int main(void) {
	int c ;
	//string s;
	cin >> c;

	for (int i = 0; i < c; i++) {
		cin >> s;
		string::iterator k = s.begin();
		string reverse = reverse_quad(k);
		cout << reverse << endl;
	}
	system("pause");
	return 0;
}