#define _CRT_SECURE_NO_WARNINGS // scanf 보안 경고로 인한 컴파일 에러 방지
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <Windows.h>


char buffer[3072][6044];
void pick(int x, int y, int N) {
	if (N == 3) {
		buffer[y][x + 2] = '*';
		buffer[y + 1][x + 1] = '*';
		buffer[y + 1][x + 3] = '*';
		for (int i = 0; i < 5; ++i) {
			buffer[y + 2][x + i] = '*';
		}
		return;
	}
	
	pick(x + N / 2, y, N / 2);
	pick(x, y + (N / 2), N / 2); 
	pick(x + N, y + (N / 2), N / 2);
}

int main() {
	int N;
	scanf("%d", &N);
	pick(0, 0, N);
	for (int j = 0; j < N; ++j) {
		for (int i = 0; i < (N * 2) - 1; ++i) {
			if (buffer[j][i] != '\0') printf("%c", buffer[j][i]);
			else printf("%c", 32);
		}
		
		printf("\n");
	}
	system("pause");
	return 0;
}