#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstring>
#include <queue>
#include <stack>
#include <functional>
#include <stdio.h>
using namespace std;
#define infinite 987654321
int n,m;
int start, dest;
int bus[1003][1003] = { 0 };
vector <int> q[1003];
priority_queue < pair<int, int> > pq;

int main(void) {
	int n;
	int from=0, to=0, cost=0;
	scanf("%d %d", &n, &m);
	
	
	for (int i = 1; i <= m;i++ ) {
		printf("%d\n", i);
		scanf("%d %d %d\n", &from, &to, &cost);
		
		
		printf("from :%d to :%d cost:%d , %d", from, to, cost,bus[from][to]);
		q[from].push_back(to);
		
	}
	printf("버스 입력 종료 ");
	scanf("%d %d ", &start, &dest);
	printf("%d %d ", start, dest);
	//dij
	int dist[1003] = { infinite };
	int prev[1003] = { -1 };

	dist[start] = 0;
	prev[start] = start;
	
	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		int a = pq.top().second;
		int a_cost = (pq.top().first)*-1;
		pq.pop();

		if (dist[a] < a_cost)	continue;

		for (int i = 0; i < q[a].size(); i++) {
			int b = q[a][i];//a->b
			int b_cost = bus[a][b];
			if ((b_cost + a_cost) < dist[b]) {
				dist[b] = b_cost + a_cost;
				prev[b] = a;
				pq.push(make_pair((dist[b])*-1, b));
			}
		}
		
	}
	//1. 최소비용 
	printf("%d \n", dist[dest]);

	system("pause");
	return 0;
}