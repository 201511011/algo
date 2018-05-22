#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char chop[50];
int c = 0;

void put01(char s1[],int c,char v1) {
	s1[c-1] = v1;
}

void reset(char* s1,int c) {
	s1 = { 0 };
	c = 0;
}

char quad(char s1[]) {
	int k=0;
	char d = s1[c];
/*	char *c1 = (char*)malloc(sizeof(char) * 20);
	char *c2 = (char*)malloc(sizeof(char) * 20); 
	char *c3 = (char*)malloc(sizeof(char) * 20); 
	char *c4 = (char*)malloc(sizeof(char) * 20); 
*/
	//*d=s1[c];
	c++;
	// printf("%d", c);
	if (d == 'w' || d == 'b') {
		put01(chop, c, d);
		return d;
	}

	else if (d == 'x') {//1->3,2->4,3->1,4->2
		chop[c - 1] = 'x';
	/*	chop[k + c] = quad(&s1[c]+2);//c==1에서 시작 xwwbb일 경우 3
		chop[k + c] = quad(&s1[c]+2);
		chop[k + c] = quad(&s1[c]-2);
		chop[k + c] = quad(&s1[c]-2);
		*/
		quad(&s1[c] + 2);  
		printf("%d\n", c);
		quad(&s1[c] + 2);
		printf("%d\n", c);
		quad(&s1[c] + 2);
		printf("%d\n", c);
		quad(&s1[c] + 2);
		printf("%d\n", c);

		return 'm';
		
	}
	
}

int main(void) {

	int k = 0,i=0;
	char s1[50];
	
	scanf("%d", &k);

	for (i = 0; i < k; i++) {
		scanf("%s",s1);
		quad(s1);
		printf("%s", s1);
		printf("%s\n", chop);

		reset(chop,c);
		printf("%s %d", chop, c);
	}
	system("pause");
	return 0;
}