
#define _CRT_SECURE_NO_WARNINGS // scanf 보안 경고로 인한 컴파일 에러 방지
#include <Windows.h>
#include <stdio.h>


int main()
{
	int i;
	int m;
	int num;


	scanf("%d%d%d", &i, &m, &num);
	printf("%d %d %d", i, m, num);
	system("pause");
	return 0;

}
