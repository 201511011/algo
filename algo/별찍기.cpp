#define _CRT_SECURE_NO_WARNINGS // scanf 보안 경고로 인한 컴파일 에러 방지
#include <Windows.h>
#include <stdio.h>

char star[4000][7000] ;

void print_star(int n, int g, int w) {//n=높이 , g= 높이1 , w = 가로 

	//degenerate case 
	if (n == 3) { //가장 작은 삼각형 별 입력 
		//일단
		star[g][w + 2] = '*';
		//이단 
		star[g + 1][w + 1] = '*';
		star[g + 1][w + 3] = '*';
		//삼단  
		star[g + 2][w] = '*';
		star[g + 2][w + 1] = '*';
		star[g + 2][w + 2] = '*';
		star[g + 2][w + 3] = '*';
		star[g + 2][w + 4] = '*';
	
		return;
	}
	//DnC
	else {
		print_star((n / 2), g, w + (n / 2));//위쪽
		print_star((n / 2), g + (n / 2), w + n);//오른쪽
		print_star((n / 2), g + (n / 2), w);//왼쪽
	}
}

int main(void) {

	int n = 0,i=0,k=0;
	//값 받기  
	scanf("%d", &n);
	//* 배열에 입력 받기 
	print_star(n,0,0);

	//결과 출력 
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < (n * 2) ; k++) {
			if (star[i][k] != NULL) {
				printf("%c", star[i][k]);
			}
			else
				printf(" ");
		}
		printf("\n");
	}

	system("pause");
	return 0;
}