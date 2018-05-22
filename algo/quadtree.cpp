#define _CRT_SECURE_NO_WARNINGS // scanf 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>
int m;
char quadtree(char* s1,int num) { //쿼드 트리 뒤집기 
	char s2[100] ;//변형 쿼드트리 
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
	char word[100];//원본 쿼드트리
	char* s = word;
	
	printf("c:");//contrl + f5 c의 값을 받음.
	scanf("%d", &c);
	printf("quadtree값을 입력하세요 : ");
	scanf("%s", s);
	
	printf("==========change==========\n");


	for (i ; i <= c; i++) { // 변경한 quadtree값을 출력.
		printf("%d번째 함수 호출\n", i + 1);
		quadtree(s,1);
	}

	return 0;
}