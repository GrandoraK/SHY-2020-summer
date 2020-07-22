#include <stdio.h>
#define WIDTH 10
#define HEIGHT 10

int screen[WIDTH][HEIGHT] = {
	0, 0, 0,-1,-1,-1,-1,-1,-1,-1,
	-1,-1, 0,-1,-1,-1,-1,-1,-1,-1,
	-1, 0, 0, 0, 0, 0, 0,-1,-1,-1,
	-1,-1,-1,-1, 0,-1, 0,-1,-1,-1,
	-1,-1,-1,-1, 0,-1, 0,-1,-1,-1,
	-1,-1, 0, 0, 0,-1, 0, 0, 0,-1,
	-1,-1,-1,-1, 0,-1, 0,-1,-1,-1,
	-1,-1,-1,-1, 0,-1, 0,-1, 0,-1,
	-1,-1,-1,-1, 0,-1,-1,-1, 0,-1,
	-1,-1,-1,-1, 0, 0, 0, 0, 0, 0
};

void flood_fill(int x, int y)
{
	static int count = 1;
	//int num;
	if (screen[x][y] == 0)
	{
		screen[x][y] = count++;
		if (y + 1 < HEIGHT)
			flood_fill(x, y + 1); // 3�ù���
		if (x + 1 < WIDTH)
			flood_fill(x + 1, y); // 6��
		if (y - 1 >= 0)
			flood_fill(x, y - 1); // 9��
		if (x - 1 >= 0)
			flood_fill(x - 1, y); // 12��
	}
}

int main(void) {
	int i, j;

	//ä��� �� ǥ ���
	printf("�̷�: \n");
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++)
			printf("%3d", screen[i][j]);
		printf("\n");
	}

	//ǥ ä���
	flood_fill(0, 0);

	//ä�� �� ǥ ���
	printf("\n�������� <0 0>���� �� �̷ι湮(����ǥ��): \n");

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++)
			printf("%3d", screen[i][j]);
		printf("\n");
	}
}