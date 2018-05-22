//https://www.acmicpc.net/problem/2437
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
priority_queue <int> pq;
int mi;
int var;

int gree() {
	mi = 0;//정수 최소값 
	int max = 0;
	int num = pq.top()*-1;
	int num2 = 0;
	if (num != 1) 	return 1;
	
	else {
		while (!pq.empty()) {
			num = pq.top()*-1;
			num2 = num2 + num;//최대
			if (mi+1 < num) {
				return mi+1 ;
			}
			else {
				mi = num2;
				pq.pop();
			}
		}
		
	}
	
	return num2+1;
}
	

int main(void) {
	scanf("%d", &n);
	int num;
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		pq.push(num*-1);//오름차순 정렬
	}

	printf("%d\n",gree());

//	system("pause");
	return 0;
}
