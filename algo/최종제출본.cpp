#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int grap[101][101] = { 0 };//0���� �ʱ�ȭ 
bool visit[10001];
vector <int> papa;
int q = 0;
int n, m;

//dfs //�湮 =1 �湮x=0

void dfs(int y, int x) {
	if (grap[y][x] == 1||y>m||x>n||x<0||y<0) {//�̹� �湮�� 
		return;
	}
	else {
		grap[y][x] = 1;
		q = q + 1;
		//�湮 
		if (y - 1 >= 0)		dfs(y - 1, x);
		if (x - 1 >= 0)	    dfs(y, x - 1);
		if (y + 1 < m)		dfs(y + 1, x);
		if (x + 1 < n)		dfs(y, x + 1);
		
	}
	return;
}
int main(void) {
	int  k=0;
	int x1, y1, x2, y2;
	int i = 0;
	int x = 0, y = 0;
	scanf("%d %d %d", &m, &n, &k);//n*m�迭 
	
	for (i = 1; i <=k; i++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		
		for (y = y1; y < y2; y++) {
			for (x = x1; x < x2; x++) {
				grap[y][x] = 1;
			}
		}
		
	}

//	initvisit();

	for (i = 0; i < m; i++) {
		for (k = 0; k < n; k++) {
			if (grap[i][k] == 0) {//���� �湮���� ��..
				q = 0;
				dfs(i, k);
				papa.push_back(q);
			}
		}

	}

	sort(papa.begin(), papa.end());

	printf("%d\n", papa.size());
	for (int i = 0; i <papa.size(); i++)
		printf("%d ", papa[i]);

	
	return 0;
}

