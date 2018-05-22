//https://www.acmicpc.net/problem/010451
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

int t, n;
int s;
int cot=0;
int grap[1011];
int visit[1011] = { 0 };


void dfs(int k) {
	
	int c = grap[k];//k->c
	visit[k] = 1;
	//if (visit[c] == 1)	return;//이미 방문한 경우
	if (c == s) {
		
		return;//k->k 인 경우 종료 
	}
	//k node 방문 표시
	//c가 방문하지 않은 노드 인 경우 dfs 진행 
	dfs(c);
}
void init() {
	
	for (int i = 0; i < 1011; i++) {
		visit[i] = 0;
		grap[i] = 0;
		
	}
}
int main(void) {
	int num=0;
	scanf("%d", &t);
	

	for(int i=0;i<t;i++) {
		scanf("%d", &n);

		for (int k = 1; k <= n; k++) {
			cin >> grap[k];//배열 받기 
			
		}
		cot = 0;
		for (int k = 1; k <= n; k++) {//dfs 수행 
		
			if (visit[k] == 0) {//k->c c가 방문 전 
				s = k;//start 노드 = k 
				dfs(k);
				cot++;
			}

		}

		printf("%d\n", cot);
		init();
		
	}

	return 0;
}