#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int n;
vector <int> mama;

int q=0;

int grap[101][101] = { 0 };
int visit[101][101] = { 0 };

void dfs(int y, int x) {
	if (visit[y][x] == 1 || y>n || x>n || x<0 || y<0) {//이미 방문함 
		return;
	}
	else {
		visit[y][x] = 1;
		//q = q + 1;
		//방문 
		if (y - 1 >= 0)		dfs(y - 1, x);
		if (x - 1 >= 0)	    dfs(y, x - 1);
		if (y + 1 < n)		dfs(y + 1, x);
		if (x + 1 < n)		dfs(y, x + 1);

	}
	return;
}
int main(void) {

	int i = 0, k = 0,p=0;
	int m = 2, M = 5;
	scanf("%d\n", &n);
	
	for (i = 0; i < n; i++) {
		for (k = 0; k < n; k++) {
			scanf("%d", &grap[i][k]);
			if (grap[i][k] < m)	m = grap[i][k];
			if (grap[i][k] > M)	M = grap[i][k];
		}
	}
	
	for (p = m; p < M; p++) {
		q = 0;
		for (i = 0; i < n; i++) {
			for (k = 0; k < n; k++) {
				if (grap[i][k] <= p)  
					visit[i][k] = 1; 
				else	visit[i][k] = 0;
			}
		}
		
		for (i = 0; i < n; i++) {
			for (k = 0; k < n; k++) {
				if (visit[i][k] == 0) {//아직 방문전일 때..
					q++;
					dfs(i, k);
				}
			}
		}
		if (q == 0)q = 1;
		mama.push_back(q);
	}


	int max = *max_element(mama.begin(), mama.end());
	printf("%d\n", max);
	
	
	return 0;

}