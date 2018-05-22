#define _CRT_SECURE_NO_WARNINGS // scanf ���� ���� ���� ������ ���� ����
#include <Windows.h>
#include <stdio.h>

char star[4000][7000] ;

void print_star(int n, int g, int w) {//n=���� , g= ����1 , w = ���� 

	//degenerate case 
	if (n == 3) { //���� ���� �ﰢ�� �� �Է� 
		//�ϴ�
		star[g][w + 2] = '*';
		//�̴� 
		star[g + 1][w + 1] = '*';
		star[g + 1][w + 3] = '*';
		//���  
		star[g + 2][w] = '*';
		star[g + 2][w + 1] = '*';
		star[g + 2][w + 2] = '*';
		star[g + 2][w + 3] = '*';
		star[g + 2][w + 4] = '*';
	
		return;
	}
	//DnC
	else {
		print_star((n / 2), g, w + (n / 2));//����
		print_star((n / 2), g + (n / 2), w + n);//������
		print_star((n / 2), g + (n / 2), w);//����
	}
}

int main(void) {

	int n = 0,i=0,k=0;
	//�� �ޱ�  
	scanf("%d", &n);
	//* �迭�� �Է� �ޱ� 
	print_star(n,0,0);

	//��� ��� 
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