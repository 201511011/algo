//#include <bits / stdc++.h>

#include <string>
#include <iostream>
#include <vector>
using namespace std;
int arr[150][150], white, blue;

void f(int i, int j, int n) {
	bool c = true;
	int sum = arr[i][j];
	if (n == 1) {
		if (sum == 0) white++;
		if (sum == 1) blue++;
	}
	else {
		for (int k = i; k<i + n; k++) {
			for (int l = j; l<j + n; l++) {
				if (sum != arr[k][l]) c = false;
			}
		}
		if (c) {
			if (sum == 0) white++;
			if (sum == 1) blue++;
		}
		else {
			int num = n / 2;
			f(i, j, num);
			f(i + num, j, num);
			f(i, j + num, num);
			f(i + num, j + num, num);
		}
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	f(1, 1, n);
	cout << white << endl << blue;
	system("pause");
	return 0;
}

