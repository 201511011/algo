#include <iostream> 


+ #include <algorithm>


+ #include <cstdio>


+ #include <string.h>


+ using namespace::std;


+


+


+char arr[3073][6145];


+


+


+void recur(int x, int y, int t)


+ {


	+if (t == 3) // �غ� ���̰� 3�̸� �ּҴ����̹Ƿ� 


		+ {


		+arr[y][x] = '*';


		+


			+arr[y + 1][x - 1] = arr[y + 1][x + 1] = '*';


		+


			+for (int i = -2; i <= 2; i++)


			+ arr[y + 2][x + i] = '*';


		+}


	+else


		+ {


		+		// ������, ���� �Ʒ�, ������ �Ʒ� ���� 


			+recur(x, y, t / 2);


		+		// �ܰ谡 24�϶� ���� recur�� x��ǥ�� +- 12, 


			+		// y�� + 12�ϱ� 


			+recur(x - t / 2, y + t / 2, t / 2);


		+recur(x + t / 2, y + t / 2, t / 2);


		+}


	+}


+


+int main(void)


+ {


	


		+int n;


	+cin >> n;


	+


		+for (int i = 0; i < n; i++)


		+ {


		+memset(arr[i], ' ', sizeof(arr[i]));


		+}


	+


		+int length = 5 * (n / 3);


	+if (n != 3) length += ((n / 3) - 1);


	+recur(length / 2, 0, n);


	+


		+for (int i = 0; i < n; i++)


		+ {


		+arr[i][length] = '\n';


		+arr[i][length + 1] = '\0';


		+printf("%s", arr[i]);


		+}


	+


		+return 0;


	+}