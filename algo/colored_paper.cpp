#define _CRT_SECURE_NO_WARNINGS // scanf 보안 경고로 인한 컴파일 에러 방지
#include <Windows.h>
#include <stdio.h>

int p[10][10] ;//색종이의 색을 입력받을 배열
int w=0 , b=0 ; //색종이 색의 수 

void colored_paper(int n, int y, int x) {

	int i = 0, k = 0 ,f=0;
	
	
	if (n == 1) {
		if (p[y][x] == 0) {
			w++;
			return;
		}
		else if (p[y][x] == 1) {
			b++;
			return;
		}
	}

	
	fofo:for (i = y; i < y + n; i++) {
			for (k = x; k < x + n; k++) {
				if (p[y][x] != p[i][k]) goto fofofo;
			}
		}
		
		if (p[y][x] == 0) {
			w++;
			return;
		}
		else if (p[y][x] == 1) {
			b++;
			return;
		}
		
		//divide and conquer 
fofofo:	
			colored_paper(n / 2, y, x);
			colored_paper(n / 2, y, x + (n / 2));
			colored_paper(n / 2, y + (n / 2), x);
			colored_paper(n / 2, y + (n / 2), x + (n / 2));
			return;

}

int main(void){

	int fu = 0,i=0,k=0;
	
	scanf("%d", &fu);
	
	for (i = 0; i < fu; i++) {
		for (k = 0; k < fu; k++) {
			scanf("%d", &p[i][k]);	
		}
	}
	colored_paper(fu,0,0);
	printf("%d\n%d", w);
	printf("%d",  b);
	system("pause");
	return 0;
}