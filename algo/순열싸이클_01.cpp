
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

int grap[1001][1001] = { 0 };
int visit[1001] = { 0 };
int t=0,n = 0,num=0;
int s;
vector <int> mama;
vector <int> papa;
void dfs(int u) {
	visit[u] == 1;
	if (s == u) {
		num++;
		return; 
	}
	else {
		int c = papa[u];
		if (visit[c] == 0 && grap[u][c] == 1)	dfs(c);
	}
}
int main(void) {
	scanf("%d\n", &t);

	 while(t--){//test

		scanf("%d", &n);
		for (int k = 0; k<=n; k++) {//배열 넣기
			int c = 0;
			scanf("%d", &c);
			grap[k][c - 1] = 1;
			papa.push_back(c - 1);
		}

		num = 0;
		for (int i = 0; i < n; i++) {
		
				s = i;
				int c = papa[i];
				if (visit[c] == 0 && grap[i][c] == 1)	dfs(c);
			
		}

		mama.push_back(num);

		for (int i = 0; i < n; i++) {//초기화 
			visit[i] = 0;
			for (int k = 0; k < n; k++) {
				grap[i][k] = 0;
			}
		}
		
	}
	 for (int i = 0; i <mama.size(); i++)
		 printf("%d\n ", mama[i]);

	scanf("%d\n", n);
	return 0;
}