//https://www.acmicpc.net/problem/11403

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstring>
#include <queue>
#include <stack>
#include <functional>

using namespace std;
int n;
int dist[101][101] = { 0 };
int cost[101][101] = { 0 };

void floyd() {
	int i, j, k;


	for (k = 0; k < n; k++) {//i->j
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				if (cost[i][k] + cost[k][j] == 2 || cost[i][j] == 1)
					cost[i][j] = 1;
	}

}
int main(void) {

	scanf("%d ", &n);

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			scanf("%d", &cost[i][k]);
		}
	}

	floyd();


	//Ãâ·Â 
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			printf("%d ", cost[i][k]);
		}
		printf("\n");
	}


	return 0;
}