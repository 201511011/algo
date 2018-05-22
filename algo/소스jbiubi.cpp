	//https://www.acmicpc.net/problem/11779
	#define _CRT_SECURE_NO_WARNINGS
	#include <iostream>
	#include <cstdio>
	#include <queue>
	#include <vector>
	#include <stack>
	#include <stdlib.h>
	using namespace std;
#define INF 987654321
	int n, m;
	priority_queue < pair<int, int> > pq;
	int bus[1003][1003];
	vector <int> q[1003];
	stack <int> path;


	int main()
	{
		
	
		scanf("%d %d", &n, &m);

	
		for (int i = 0; i < m; i++)
		{
			int from, to, cost;
			scanf("%d %d %d", &from, &to, &cost);

			bus[from][to] = cost;
			q[from].push_back(to);
		}
		int s, e;
		scanf("%d %d", &s, &e);
		
		int visit[1003];
		fill_n(visit, 1003, 0);

		int dist[1003] ;
		fill_n(dist, 1003, INF);

		int prev[1003];
	
		dist[s] = 0;

		pq.push(make_pair(0, s));
	
		while (!pq.empty()) {

			int a = pq.top().second;
			long a_cost = (pq.top().first)*-1;
			pq.pop();
			if (dist[a] < a_cost ||visit[a]==1) {
				continue;
			}
			visit[a] = 1;
			for (int i = 0; i < q[a].size(); i++) {
				int b = q[a][i];//a->b
				int b_cost =  dist[a] + bus[a][b] ;

				if (visit[b] == 1) {
					continue;
				}
				
				if ( b_cost< dist[b]) {
					dist[b] = b_cost;
					prev[b] = a;
					pq.push(make_pair((dist[b])*-1, b));
				}
			}

		}
		//1. 최소비용 
		printf("%d \n", dist[e]);
		//2. 도시수 //3. 경로  
		int count = 1;
		int i = e;
		while (i != s) {
			path.push(i);
			i = prev[i];
			count++;
		}
		path.push(s);
		printf("%d\n", count);
	
		while (!path.empty()) {
			printf("%d ", path.top());
			path.pop();
		}
	
		
		return 0;
	}
