#define _CRT_SECURE_NO_WARNINGS // scanf ���� ���� ���� ������ ���� ����
#include <stdio.h>
#include <string.h>
#include <Windows.h>
char chop[100] = { 0 };
int c=0;

char quadtree(char* s1, int num) { //���� Ʈ�� ������ 
	//char ma1[10],ma2[10],ma3[10],ma4[10];
	char *ma1 = (char*)malloc(sizeof(char) * 20);
	char *ma2 = (char*)malloc(sizeof(char) * 20);
	char *ma3 = (char*)malloc(sizeof(char) * 20);
	char *ma4 = (char*)malloc(sizeof(char) * 20);
	int i = 0;
	printf("quadtree����\n");
	c++;
	printf("%d", c);
	if (*(s1+(c-1)) == 'x') {// quadtree�� �Է°��� 'x'�� ��� 

		*ma1 = quadtree(s1, c);
		printf("%d", c);
		*ma2 =quadtree(s1, c);
		printf("%d", c);
		*ma3 = quadtree(s1, c);
		printf("%d", c);
		*ma4 =quadtree(s1, c );
		printf("%d", c);

		*ma3 = 'x' + *ma3 + *ma4 + *ma1 + *ma2;
		printf("%s", *ma3);
		return *ma3 ;
		
	}
	else if (*(s1 + (c-1)) == 'w'|| *(s1 + (c - 1)) == 'b') { //quadtree�� ���� x�� �ƴ� ��� --> 4 �ڸ� �߿� �ϳ��̴�.

		return *(s1+(c-1));
	}

	
}



int main(void) {
	int st = 0;
	//int num = 0;
	int i = 0;
	char s1[100] = { 0 };//���� ����Ʈ��
	char s2[100] = { 0 };
	printf("c:");//contrl + f5 c�� ���� ����.
	scanf("%d", &st);
	
	for (i = 0; i < st; i++) {  //�� ���� ���� �迭�� ������� 
		//�ʱ�ȭ 
		c = 0;	
		strcpy(s2, s1);
		//������ֱ� 
		//printf("%d° �Է�:", i + 1);
		scanf("%s", s1); 
		//strcpy(chop, s1);
		printf("%s\n", s1);
		//reverse
		quadtree(s1, c); 
		printf("%s\n", s1);  
		
	}
	system("pause");


	return 0;
}