#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int grap[101][101] = { 0 };//0���� �ʱ�ȭ 
vector <int> papa;
int q = 0;
int n, m;

//dfs //�湮 =1 �湮x=0
void dfs(int y, int x) {
	if (grap[y][x] == 1) {//�̹� �湮�� 
		return;
	}
	if (x - 1 < 0 || y - 1 < 0)	return;
	if (x + 1 > n || y + 1 > m)	return;
	q = q + 1;
	grap[y][x] = 1;//�湮 
	//�� �簢�� ���� 4�� 
	//dfs(y, x-1);
	dfs(y, x + 1);
	dfs(y + 1, x);
	dfs(y - 1, x);
	return ;
}
int main(void) {
	int  k;
	int x1,y1,x2,y2;
	int i = 0, k = 0;
	int x = 0, y = 0;
	scanf("%d %d %d", &m, &n, &k);//n*m�迭 


	for ( i = 0; i < k; k++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		//�湮 =1 
		for ( y = y1; y < y2; y++) {
			for ( x = x1; x < x2; x++) {
				grap[y][x] = 1;
				
			}
		}
	}
	
	for ( i = 1; i <= n; i++) {
		for ( k = 1; k <= m; k++) {
			if (grap[k][i] == 0) {//���� �湮���� ��..
				q = 0;
				dfs(k,i);
				papa.push_back(q);
			}
		}
	
	}
	sort(papa.begin(), papa.end());

	printf("%d\n", papa.size());
	for (int i = 0; i < papa.size(); i++)
		printf("%d ", papa[i]);

	system("pause");
	return 0;
}

