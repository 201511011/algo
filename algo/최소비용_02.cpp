//https://www.acmicpc.net/problem/11779
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


# define infinite 1000000000
int prev[1010];
int n = 0, b = 0, cost = 0;
int s = 0, e = 0;

int prev3[1001];
vector < pair<int, int> > bus[10010];
priority_queue < pair<int, int> > pq;
int i = 0;

int dij(int start) {
	
	printf("dij시작 :%d\n", start);

	int dist[1010] = { infinite };
	
	dist[start] = 0;
	pq.push(make_pair(0, start));

	while (!pq.empty()) {

		int here = pq.top().second;
		int herecost = (pq.top().first)*-1;//max->min 
		pq.pop();

		if ((herecost <= dist[here])) {
			for (int i = 0; i < bus[here].size(); i++) {

				int next = bus[here][i].second;
				int nextcost = bus[here][i].first;

				if (dist[next] > nextcost + herecost) {
					dist[next] = nextcost + herecost;
					pq.push(make_pair(((dist[next])*(-1)), next));//max->min
					prev3[next] = here;
					printf("%d ,%d ", prev3[next],dist[next]);
				}
			}
		}
	}
	return dist[e];
}


int main(void) {
	int n1, n2, n3;
	stack <int> path;

	scanf("%d %d", &n, &b);
	
	for (int i = 0; i < b; i++) {
		scanf("%d %d %d\n", &n1, &n2, &n3);
		bus[n1].push_back(make_pair(n2, n3));
	}
	scanf("%d %d", &s, &e);
	printf("mama : %d %d\n ",s, e);

	int min_cost=dij(s);
	//1.최소비용 
	printf("%d \n", min_cost);
	//2.도시개수 
	int cs = 1;
	//3.경로 
	int i = e;
	for(i;i!=s;i=prev3[i]) {
		printf("work");
		path.push(i);
		cs++;
	}
	path.push(s);

	printf("%d \n",cs);
	while (!path.empty()) {
		printf("%d ", path.top());
		path.pop();
	}
	system("pause");
	return 0; 
}