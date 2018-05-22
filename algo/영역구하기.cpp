#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int grap[101][101] = { 0 };//0으로 초기화 
vector <int> papa;
int q = 0;
int n, m;

//dfs //방문 =1 방문x=0
void dfs(int y, int x) {
	if (grap[y][x] == 1) {//이미 방문함 
		return;
	}
	if (x - 1 < 0 || y - 1 < 0)	return;
	if (x + 1 > n || y + 1 > m)	return;
	q = q + 1;
	grap[y][x] = 1;//방문 
	//한 사각형 연결 4개 
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
	scanf("%d %d %d", &m, &n, &k);//n*m배열 


	for ( i = 0; i < k; k++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		//방문 =1 
		for ( y = y1; y < y2; y++) {
			for ( x = x1; x < x2; x++) {
				grap[y][x] = 1;
				
			}
		}
	}
	
	for ( i = 1; i <= n; i++) {
		for ( k = 1; k <= m; k++) {
			if (grap[k][i] == 0) {//아직 방문전일 때..
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

