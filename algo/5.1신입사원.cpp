//https://www.acmicpc.net/problem/1946
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

int t, n,pass;
int mem[100001][2];
priority_queue < pair<int, int> > pq;

int gree(void){
	 pass = 1;//�������� 1�� 
	
	//�������� �������� 

	int min = pq.top().second;//�������� 1�� ���� ���� 
	pq.pop();
	while(!pq.empty()) {
	//	printf("gree while�� ����: %d\n",k);
	//	printf("min : %d  -- %d %d\n",min, pq.top().first, pq.top().second);
		if (min > pq.top().second) {
	//		printf("����\n");
			min = pq.top().second;
			pass++;
			pq.pop();
		}
		else pq.pop();
	//	k++;
	}
	return pass;
}

int main(void) {
	scanf("%d", &t);
	int num1, num2;
	while (t>0) {
	
		scanf("%d", &n);
		while (!pq.empty()) pq.pop();//pq �ʱ�ȭ 

		for (int i = 0; i < n; i++) {
			scanf("%d %d", &num1,&num2);
			pq.push(make_pair(num1*-1, num2));//�������� 
			
		}
		
		printf("%d\n", gree());
		t--;
	}

//	system("pause");
	return 0;
}