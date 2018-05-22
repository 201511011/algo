#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int m;
//vector <int> c;
int c[500001];


//정렬되어 있는 vecotr c에서 val2가 몇개 있는지 찾아보고 그 수를 return 한다. 
int card(int val) {
	
	return (upper_bound(v.begin(), v.end(), val) - v.begin()) - (lower_bound(v.begin(), v.end(), val) - v.begin());
}

int main(void) {
	int val = 0;
	scanf("%d", &n);
	free(c);
	c 
	
	for (int i = 0; i<n; i++) {
		int num;
		scanf("%d", &num);
		c[i] = num;
	}

	sort(c, c + n);//오름차순으로 정렬 
	typedef std::vector<int> IntVector;
	IntVector v(c, c + sizeof(c) / sizeof(c[0]));
	//3. m 입력 
	scanf("%d\n", &m);

	//4.상근이가 몇 개 가지고 있는 숫자 카드인지 구해야 할 M개의 숫자, 이 숫자는 공백으로 구분 
	for (int k = 0; k < m; ++k) {//m번 값을 받음. 받을 때마다 card()함수 호출 
		scanf("%d ", &val);
		printf("%d ", card(val));
	}
	return 0;
}