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
# define infinite 987654321
int n, b;
int start;
int dest;

vector <pair<int, int>> bus[1010];
typedef pair<int, int> tem;
priority_queue<tem, vector<tem>, greater<tem>> pq;


int main(void) {
	int n1, n2, n3;
	scanf("%d %d", &n, &b);
	for (int i = 0; i < b; i++) {
		scanf("%d %d %d\n", &n1, &n2, &n3);
		bus[n1].push_back(make_pair(n2, n3));
	}
	scanf("%d  %d\n", &start, &dest);

	//dij
	int prev[1010] ;
	int path[1010]  ;
	int dist[1010] = { infinite };
	int count = 1;
	vector <int> papa;

	dist[start] = 0;
	prev[start] = -1;


	for (int i = 1; i <= n; i++) {//pq에 pri=cost ,city 넣기 
		pq.push({ dist[i],i });
	}

	while (!pq.empty()) {
		int one = pq.top().second;
		int onecost = pq.top().first;
		pq.pop();
		
			for (int i = 0; i < bus[one].size(); i++) {//one 과 연결된 모든 edge 
				int two = bus[one][i].second;
				int twocost = bus[one][i].first + onecost;
				if (twocost < dist[two]) {
					dist[two] = twocost;
					prev[two] = one;
				}
			}
		
	}
		
//1. 최소비용 
	printf("%d\n", dist[dest]);
//2. 도시 개수 //3. 도시 순서
	int city=dest;
	//for (int i = dest; i != start; i = prev[i]) {
	//	papa.push_back(i);
	//	count++;
	//}
	while (city != start) {
		papa.push_back(city);
		int k= prev[city];
		city = k;
		count++;
	}
	papa.push_back(start);
	printf("%d \n", count);
	papa.push_back(start);
	::std::reverse(papa.begin(), papa.end());

	for (int i = 0; i < papa.size(); i++) {
		printf("%d ", papa[i]);
	}
	
 


	system("pause");
	return 0;
}

