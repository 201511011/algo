#define _CRT_SECURE_NO_WARNINGS // scanf ���� ���� ���� ������ ���� ����
#include <stdio.h>
int m;
char quadtree(char* s1,int num) { //���� Ʈ�� ������ 
	char s2[100] ;//���� ����Ʈ�� 
	int i , num2 = 0;
	if(s1)
	if (*s1 == 'w' || *s1 == 'b') {
		return *s1;
	}

	else if (*s1 == 'x') {


	}
	
			
}



int main(void) {
	int c = 0, i = 1;
	char word[100];//���� ����Ʈ��
	char* s = word;
	
	printf("c:");//contrl + f5 c�� ���� ����.
	scanf("%d", &c);
	printf("quadtree���� �Է��ϼ��� : ");
	scanf("%s", s);
	
	printf("==========change==========\n");


	for (i ; i <= c; i++) { // ������ quadtree���� ���.
		printf("%d��° �Լ� ȣ��\n", i + 1);
		quadtree(s,1);
	}

	return 0;
}