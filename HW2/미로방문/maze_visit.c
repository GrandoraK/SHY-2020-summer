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
			flood_fill(x, y + 1); // 3시방향
		if (x + 1 < WIDTH)
			flood_fill(x + 1, y); // 6시
		if (y - 1 >= 0)
			flood_fill(x, y - 1); // 9시
		if (x - 1 >= 0)
			flood_fill(x - 1, y); // 12시
	}
}

int main(void) {
	int i, j;

	//채우기 전 표 출력
	printf("미로: \n");
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++)
			printf("%3d", screen[i][j]);
		printf("\n");
	}

	//표 채우기
	flood_fill(0, 0);

	//채운 후 표 출력
	printf("\n시작점을 <0 0>으로 한 미로방문(순서표기): \n");

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++)
			printf("%3d", screen[i][j]);
		printf("\n");
	}
}