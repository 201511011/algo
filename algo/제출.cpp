#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int m;
//vector <int> c;
int c[500001];


//���ĵǾ� �ִ� vecotr c���� val2�� � �ִ��� ã�ƺ��� �� ���� return �Ѵ�. 
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

	sort(c, c + n);//������������ ���� 
	typedef std::vector<int> IntVector;
	IntVector v(c, c + sizeof(c) / sizeof(c[0]));
	//3. m �Է� 
	scanf("%d\n", &m);

	//4.����̰� �� �� ������ �ִ� ���� ī������ ���ؾ� �� M���� ����, �� ���ڴ� �������� ���� 
	for (int k = 0; k < m; ++k) {//m�� ���� ����. ���� ������ card()�Լ� ȣ�� 
		scanf("%d ", &val);
		printf("%d ", card(val));
	}
	return 0;
}