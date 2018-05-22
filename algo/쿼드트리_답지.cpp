#include <iostream>
#include<string>
using namespace std;


string reverse_quad(string::iterator& t) {
	char de = *t;
	t++;
	
	if (de == 'w')	return string(1,de);

	else if (de == 'b')	return string(1,de);

	else if (de == 'x') {

		string s1 = reverse_quad(t);
		string s2 = reverse_quad(t);
		string s3 = reverse_quad(t);
		string s4 = reverse_quad(t);

		return string("x") + s3 + s4 + s1 + s2;
	}
}

int main() {

	int c;
	string output;
	string s0;
	cin >> c;
	
	for (int i = 0; i < c; i++) {
		cin >> s0 ;
		string::iterator t = s0.begin();
		output = reverse_quad(t);
		cout << output << endl;
	//	output = output + string("\n");
		
	}
/*	cout << string("\n");
	cout << output << endl;
*/	system("pause");
	return 0;
}


